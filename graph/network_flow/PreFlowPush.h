/*
function:预流-推进最大流算法
by:Erland
date:2017.8.23
*/

#pragma once
#ifdef AdjList

#include "FIFO.h"
#include "FIFO_List.h"
#include "Item.h"

void graphdist(Graph G, int t, int h[])			//初始化结点距汇点的高度
{
	int i, j, n = 0, last = 0;
	link u;
	bool book[maxV];
	for (int k = 0; k < G->V; k++)
	{
		book[k] = 0;
		h[k] = -1;
	}
	book[t] = 1;
	h[t] = n++;
	Que q = InitQueue();
	PutQueue(q, t);
	PutQueue(q, -1);				//-1作为标志位
	while (!EmptyQueue(q))
	{
		j = GetQueue(q);
		if (j == -1)
		{
			last = i;
			n++;
			continue;
		}
		for (u = G->adj[j]; u != NULL; u = u->next)
		{
			if (u->cap < 0 && book[u->v] == 0)
			{
				i = u->v;
				PutQueue(q, i);
				h[i] = n;
				book[i] = 1;
			}
		}
		if (j == last)
			PutQueue(q, -1);
	}
}

void GraphMaxFlow_PP(Graph G, int s, int t)
{
	int v, w, x;
	link u;
	int h[maxV];
	graphdist(G, t, h);
	InitQue(maxV);
	for (v = 0; v < G->V; v++)
		wt[v] = 0;
	PutQue(s);
	wt[s] = maxWT;
	wt[t] = -maxWT;
	while (!EmptyQue())
	{
		v = GetQue();
		for (u = G->adj[v]; u != NULL; u = u->next)
		{
			if ((P > 0 && v == s) || h[v] == h[u->v] + 1)
			{
				w = u->v;
				x = P;
				u->flow += x;
				u->dup->flow -= x;
				wt[v] -= x;
				wt[w] += x;
				if (w != s && w != t)
					PutQue(w);
			}
		}
		if (v != s && v != t && wt[v] > 0)
		{
			h[v]++;
			PutQue(v);
		}
	}
}


#endif
