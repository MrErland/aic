/*
function:MST问题的Prim算法
by:Erland
date:2017.8.9
*/

//适合于稠密图
#pragma once
#ifdef AdjMatrix

#include "AdjMatrix.h"
static int fr[maxV];

void GraphMSTP(Graph G, int st[], double wt[])
{
	int v, w, min = 0;
	for (v = 0; v < G->V; v++)
	{
		st[v] = -1;			//生成树的父结点表示
		fr[v] = v;			//非树结点的最近树结点
		wt[v] = maxWT;		//树结点与父结点的距离，非树结点与树的距离
	}
	st[0] = 0;				//起始点
	wt[G->V] = maxWT;		//wt最后加一个位置用来保存最大权值
	while (min != G->V)
	{
		v = min;
		st[min] = fr[min];				//非树结点入树
		for (w = 0, min = G->V; w < G->V; w++)
		{
			if (st[w] == -1)			//非树结点
			{
				if (G->adj[v][w] != initWT && G->adj[v][w] < wt[w])
				{
					wt[w] = G->adj[v][w];
					fr[w] = v;
				}
				if (wt[w] < wt[min])	//非树结点距离树最近点
					min = w;
			}
		}
	}
}


#endif


//优先级优先搜索--PFS,适用于稀疏图
#ifdef AdjList

#include "AdjList.h"
#include "PQ.h"
static int fr[maxV];

void GraphMSTP(Graph G, int st[], double wt[])
{
	link t;
	int v, w;
	PQinit();
	for (v = 0; v < G->V; v++)
	{
		st[v] = -1;
		fr[v] = -1;
	}
	fr[0] = 0;
	PQinsert(wt, 0);
	while (!PQempty())
	{
		v = PQdelemin();
		st[v] = fr[v];
		for (t = G->adj[v]; t != NULL; t = t->next)
		{
			if (fr[w = t->v] == -1)
			{
				wt[w] = t->wt;
				PQinsert(wt, w);		//加入队列
				fr[w] = v;
			}
			else if (st[w] == -1 && t->wt < wt[w])
			{
				wt[w] = t->wt;
				PQdec(wt, w);			//改变优先级
				fr[w] = v;
			}
		}
	}
}

#endif
