/*
function:增大路径最大流算法
by:Erland
date:2017.8.22
*/

#pragma once
#ifdef AdjList

#include "Item.h"
#include "PQ.h"
#include "AdjList.h"

static int wt[maxV + 2];			//可行流问题 +2
#define M 9999
#define Q (u->cap < 0 ? -u->flow : u->cap - u->flow)			//残余网络
#define P (Q > wt[v] ? wt[v] : Q)								//最大容量增大路径

int graphPfs(Graph G, link st[], int s, int t)
{
	int v, w, d = M;
	link u = NULL;
	PQinit();
	for (v = 0; v < G->V; v++)
	{
		st[v] = NULL;				//用来保存路径
		wt[v] = 0;
		PQinsert(wt, v);
	}
	wt[s] = M;
	PQdec(wt, s);
	while (!PQempty())
	{
		v = PQdelemax();
		if (wt[v] == 0 || v == t)
			break;
		for (u = G->adj[v]; u != NULL; u = u->next)
		{
			if (Q > 0 && P > wt[w = u->v])
			{
				wt[w] = P;
				PQdec(wt, w);
				st[w] = u;
			}
		}
//		wt[v] = M;					//可以删去？
	}
	if (wt[t] == 0)
		return 0;
	for (w = t; w != s; w = st[w]->dup->v)
	{
		u = st[w];
		d = (Q > d ? d : Q);
	}
	return d;
}

void GraphMaxFlow(Graph G, int s, int t)
{
	int x, d;
	link st[maxV + 2];							//可行流问题 +2
	while ((d = graphPfs(G, st, s, t)) != 0)
	{
		for (x = t; x != s; x = st[x]->dup->v)
		{
			st[x]->flow += d;					//修改了G中每条路径中的流量
			st[x]->dup->flow -= d;
		}
	}
}

#endif
