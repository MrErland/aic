/*
function:Bellman-Ford算法求解负权边最短路径问题
by:Erland
date:2017.8.18
*/

#pragma once 
#ifdef AdjList

#include "FIFO.h"
#include "AdjList.h"

//FIFO优化的Bellman-Ford算法
void GraphBF(Graph G, int st[], double wt[], int s)
{
	int v, w;
	link t;
	int n = 0;
	InitQue(G->E);
	for (v = 0; v < G->V; v++)
	{
		st[v] = -1;
		wt[v] = maxWT;
	}
	wt[s] = 0;
	st[s] = s;
	PutQue(s);
	PutQue(G->V);
	while (!EmptyQue())
	{
		v = GetQue();
		if (v == G->V)
		{
			if (n++ > G->V)
				return;
			PutQue(G->V);
		}
		else{
			for (t = G->adj[v]; t != NULL; t = t->next)
			{
				if (wt[w = t->v] > wt[v] + t->wt)
				{
					wt[w] = wt[v] + t->wt;
					st[w] = v;
					PutQue(w);
				}
			}
		}
	}
}


#endif
