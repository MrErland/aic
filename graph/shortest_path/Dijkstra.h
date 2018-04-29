/*
function:Dijkstra算法--单源点SPT问题
by:Erland
date:2017.8.13
*/

#pragma once
#ifdef AdjMatrix

#include "AdjMatrix.h"
static int fr[maxV];

void GraphSPTDij(Graph G, int st[], double wt[], int s)
{
	int v, w, min = s;
	for (v = 0; v < G->V; v++)
	{
		st[v] = -1;			//生成树的父结点表示
		fr[v] = v;			//非树结点的最近树结点
		wt[v] = maxWT;		//树结点与父结点的距离，非树结点与树的距离
	}
	st[s] = s;				//起始点
	wt[s] = 0;
	wt[G->V] = maxWT;		//wt最后加一个位置用来保存最大权值
	while (min != G->V)
	{
		v = min;
		st[min] = fr[min];				//非树结点入树
		for (w = 0, min = G->V; w < G->V; w++)
		{
			if (st[w] == -1)			//非树结点
			{
				if (G->adj[v][w] != initWT && G->adj[v][w] + wt[v] < wt[w])
				{
					wt[w] = G->adj[v][w] + wt[v];
					fr[w] = v;
				}
				if (wt[w] < wt[min])	//非树结点距离树最近点
					min = w;
			}
		}
	}
}

#endif


//适用于稀疏图
#ifdef AdjList

#include "AdjList.h"
#include "PQ.h"

void GraphSPTDij(Graph G, int st[], double wt[], int s)
{
	int v, w;
	link t;
	PQinit();
	for (v = 0; v < G->V; v++)
	{
		st[v] = -1;
		wt[v] = maxWT;
		PQinsert(wt, v);
	}
	st[s] = s;
	wt[s] = 0;
	PQdec(wt, s);
	while (!PQempty())
	{
		if (wt[v = PQdelemin()] != maxWT)
		{
			for (t = G->adj[v]; t != NULL; t = t->next)
			{
				if ((wt[v] + t->wt) < wt[w = t->v])
				{
					wt[w] = wt[v] + t->wt;
					PQdec(wt, w);
					st[w] = v;
				}
			}
		}
	}
}

static int fr[maxV];
void GraphSPTDij_1(Graph G, int st[], double wt[], int s)
{
	link t;
	int v, w;
	PQinit();
	for (v = 0; v < G->V; v++)
	{
		st[v] = -1;
		fr[v] = -1;
		wt[v] = maxWT;
	}
	fr[s] = s;
	wt[s] = 0;
	PQinsert(wt, s);
	while (!PQempty())
	{
		v = PQdelemin();
		st[v] = fr[v];
		for (t = G->adj[v]; t != NULL; t = t->next)
		{
			if (fr[w = t->v] == -1)
			{
				wt[w] = t->wt + wt[v];
				PQinsert(wt, w);		//权值加入队列
				fr[w] = v;
			}
			else if (st[w] == -1 && (t->wt + wt[v]) < wt[w])
			{
				wt[w] = t->wt + wt[v];
				PQdec(wt, w);			//权值改变，堆也发生改变
				fr[w] = v;
			}
		}
	}
}


#endif
