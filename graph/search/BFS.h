/*
function:BFS Implement
by:Erland
date:2017.7.28
*/


#pragma once
#include "Item.h"
#include "Queue.h"
static int st[maxV];

#ifdef AdjMatrix
#include "AdjMatrix.h"

//BFS--搜索所有的边
void BFS(Graph G, Edge e, Q q)
{
	int v;
	PutQueue(q, e);
	while (!EmptyQueue(q))
	{
		e = GetQueue(q);
		if (pre[e.w] == -1)
		{
			pre[e.w] = cnt++;				//标记
			st[e.w] = e.v;					//记录路径
			for (v = 0; v < G->V; v++)
			{
				if (G->adj[e.w][v] == 1 && pre[v] == -1)
					PutQueue(q, EDGE(e.w, v));
			}		
		}
	}
}

//BFS--搜索所有的点 更快一些
void BFS_2(Graph G, Edge e, Q q)
{
	int v, w;
	PutQueue(q, e);
	pre[e.w] = cnt++;
	while (!EmptyQueue(q))
	{
		e = GetQueue(q);
		w = e.w;
		st[w] = e.v;
		for (v = 0; v < G->V; v++)
		{
			if (G->adj[w][v] == 1 && pre[v] == -1)
			{
				PutQueue(q, EDGE(w, v));
				pre[v] = cnt++;
			}
		}
	}
}


#endif 

#ifdef AdjList
#include "AdjList.h"

void BFS_2(Graph G, Edge e, Q q)
{
	link t;
	PutQueue(q, e);
	pre[e.w] = cnt++;
	while (!EmptyQueue(q))
	{
		e = GetQueue(q);
		st[e.w] = e.v;
		for (t = G->adj[e.w]; t != NULL; t = t->next)
		{
			if (pre[t->v] == -1)
			{
				PutQueue(q, EDGE(e.w, t->v));
				pre[t->v] = cnt++;
			}
		}
	}
}

#endif


void graphSerachBFS(Graph G, int s)
{
	int v;
	cnt = 0;
	for (v = 0; v < G->V; v++)
		pre[v] = st[v] = -1;
	Q q = InitQueue();
//	BFS(G, EDGE(-1, s), q);
	BFS_2(G, EDGE(-1, s), q);					//从s开始搜索所有的点
}


