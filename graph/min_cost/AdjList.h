/**
function:AdjList
by:Erland
date:2017.8.21
*/

#pragma once 
#ifdef AdjList

#include "Item.h"
#include "Graph.h"
#include <iostream>

/*****************************网络流邻接表--有向有权图****************************/

typedef struct node *link;
struct node{ int v; int cap; int flow; int cost;  link dup; link next; };
struct graph{ int V; int E; link* adj; int *sd; };						//sd[]表示结点的供应量(>0)或需求量(<0)

link NEW(int v, int cap, int flow, int cost, link next)
{
	link x = new node;
	x->v = v;
	x->cap = cap;
	x->flow = flow;
	x->next = next;
	x->cost = cost;
	return x;
}

Graph graphInit(int v)
{
	int i, s;
	Graph G = new graph;
	G->V = v;
	G->E = 0;
	G->adj = new link[v + 2];						//可行流问题 +2
	G->sd = new int[v];
	for (i = 0; i < v; i++)
		G->adj[i] = NULL;
	
	srand((unsigned)time(NULL));					//随机数
	for (i = 0; i < v; i++)							//生成供应量和需求量
	{
		s = rand() % 2;
		if (s == 0)
			G->sd[i] = rand() % 50 - 50;			//sd:-50~50
		else
			G->sd[i] = rand() % 50 + 1;
	}
	return G;
}

void graphInsertE(Graph G, Edge e)
{
	int v = e.v, w = e.w;
	G->adj[v] = NEW(w, e.cap, e.flow, e.cost, G->adj[v]);
	G->adj[w] = NEW(v, -e.cap, -e.flow, e.cost, G->adj[w]);
	G->adj[v]->dup = G->adj[w];
	G->adj[w]->dup = G->adj[v];
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
				a[E++] = EDGE(v, t->v, t->cap, t->flow, t->cost);
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
}

void graphShow(Graph G)
{
	int i;
	link t;
	std::cout << "Vertices: " << G->V << "\tEdges: " << G->E << std::endl;
	for (i = 0; i < G->V; i++)
	{
		std::cout << "  " << i << ":\t";
		for (t = G->adj[i]; t != NULL; t = t->next)
		{
			if (t->cap != 0)
				std::cout << "-> " << t->v << " (" << t->cap << ") (" << t->cost << ")\t";
		}
		std::cout << std::endl;
	}
}

Graph graphReverse(Graph G)					//有向有权图的逆图
{
	int v;
	link t;
	Graph R = graphInit(G->V);
	for (v = 0; v < G->V; v++)
	{
		for (t = G->adj[v]; t != NULL; t = t->next)
			graphInsertE(R, EDGE(t->v, v, t->cap, t->flow, t->cost));
	}
	return R;
}

static int flowV(Graph G, int v)
{
	link t;
	int x = 0;
	for (t = G->adj[v]; t != NULL; t = t->next)
		x += t->flow;
	return x;
}
int graphFlow(Graph G, int s, int t)			//S总流量查询
{
	int v, val;
	for (v = 0; v < G->V; v++)
	{
		if (v != s && v != t && flowV(G, v) != 0)
			return 0;
	}
	val = flowV(G, s);
	if (val + flowV(G, t) != 0)
		return 0;
	if (val <= 0)
		return 0;
	return val;
}

void flowShow(Graph G)
{
	int i, k;
	link t;
	for (i = 0; i < G->V; i++)
	{
		k = 0;
		for (t = G->adj[i]; t != NULL; t = t->next)
		{
			if (t->flow != 0)
			{
				k = 1;
				std::cout << i << "->" << t->v << ":" << t->flow << "\t";
			}
		}
		if (k == 1)
			std::cout << '\n';
	}
}

int GraphCost(Graph G)
{
	int i, cost = 0;
	link u;
	for (i = 0; i < G->V; i++)
	{
		for (u = G->adj[i]; u != NULL; u = u->next)
		{
			if (u->cap > 0 && u->cost <= 50)
				cost += (u->cost)*(u->flow);
		}
	}
	return cost;
}


#endif
