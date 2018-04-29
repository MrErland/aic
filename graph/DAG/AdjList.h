/**
function:ADT of AdjList
by:Erland
date:2017.8.1
*/

#pragma once 
#ifdef AdjList

#include "Item.h"
#include "Graph.h"

/*****************************邻接表--有向图****************************/

typedef struct node *link;
struct node{ int v; link next; };
struct graph{ int V; int E; link* adj; int* cc; int **tc; };		//邻接表表示法

link NEW(int v, link next)
{
	link x = new node;
	x->v = v;
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
	G->adj[v] = NEW(w, G->adj[v]);
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
				a[E++] = EDGE(v, t->v);
		}
	}
	return E;
}

int graphDegOut(Graph G, int v)			//计算顶点的出度 时间复杂度小于V
{
	if (G->V - 1 < v)
		return 0;
	int n = 0;
	for (link t = G->adj[v]; t != NULL; t = t->next, n++);
	return n;
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
}

Graph graphReverse(Graph G)				//有向图翻转
{
	int v;
	link t;
	Graph R = graphInit(G->V);
	for (v = 0; v < G->V; v++)
	{
		for (t = G->adj[v]; t != NULL; t = t->next)
			graphInsertE(R, EDGE(t->v, v));
	}
	return R;
}

#endif
