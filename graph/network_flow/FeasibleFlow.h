/*
function:可行流问题
by:Erland
date:2017.8.24
*/

#pragma once
#ifdef AdjList

#include "Item.h"
#include "AdjList.h"
#include "FordFulkerson.h"

void insertSTlinks(Graph G, int s, int t)
{
	int i, sd;
	G->adj[s] = NULL;
	G->adj[t] = NULL;
	for (i = 0; i < G->V; i++)
	{
		sd = G->sd[i];
		if (sd > 0)
			graphInsertE(G, EDGE(s, i, sd, 0));
		if (sd < 0)
			graphInsertE(G, EDGE(i, t, -sd, 0));
	}
}

void removeSTlinks(Graph G)
{
	int i;
	for (i = 0; i < G->V; i++)
	{
		G->adj[i] = G->adj[i]->next;			//这里只移除了指针，没有释放内存，并且每个顶点的sd必须为正或负。
		G->E--;
	}
}

int GraphFeasible(Graph G)
{
	int s = G->V, t = G->V + 1, st = 0;
	link u;
	insertSTlinks(G, s, t);
	G->V += 2;
	GraphMaxFlow(G, s, t);
	for (u = G->adj[s]; u != NULL; u = u->next)
		st += u->cap - u->flow;
	for (u = G->adj[t]; u != NULL; u = u->next)
		st += u->cap - u->flow;
	G->V -= 2;
	removeSTlinks(G);
	return st;
}



#endif
