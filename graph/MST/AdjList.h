/**
function:AdjList
by:Erland
date:2017.8.9
*/

#pragma once 
#ifdef AdjList

#include "Item.h"
#include "Graph.h"

/*****************************邻接表--无向有权图****************************/

typedef struct node *link;
struct node{ int v; double wt; link next; };
struct graph{ int V; int E; link* adj; };		//邻接表表示法

link NEW(int v, double wt, link next)
{
	link x = new node;
	x->v = v;
	x->wt = wt;
	x->next = next;
	return x;
}

Graph graphInit(int v)
{
	int i;
	Graph G = new graph;
	G->V = v;
	G->E = 0;
	G->adj = new link[v];
	for (i = 0; i < v; i++)
		G->adj[i] = NULL;
	return G;
}

void graphInsertE(Graph G, Edge e)
{
	int v = e.v, w = e.w;
	if (v == w)
		return;
	G->adj[v] = NEW(w, e.wt, G->adj[v]);
	G->adj[w] = NEW(v, e.wt, G->adj[w]);
	G->E++;
}

int graphEdges(Edge a[], Graph G)		//边数组
{
	int v, E = 0;
	link t;
	for (v = 0; v < G->V; v++)
	{
		for (t = G->adj[v]; t != NULL; t = t->next)
		{
			if (v < t->v)
				a[E++] = EDGE(v, t->v, t->wt);
		}
	}
	return E;
}

void removeE(Graph G, int s, int t)
{
	link p = G->adj[s];
	if (p == NULL)
		return;
	if (p->v == t)
	{
		G->adj[s] = p->next;
		delete p;
		return;
	}
	link q = p;
	p = p->next;
	while (p != NULL)
	{
		if (p->v = t)
		{
			q->next = p->next;
			delete p;
			return;
		}
		p = p->next;
		q = q->next;
	}
}
void graphRemoveE(Graph G, Edge e)		//删除边
{
	int a = e.v, b = e.w;
	removeE(G, a, b);
	removeE(G, b, a);
}


#endif
