/**
function:Graph ADT
by:Erland
date:2017.7.25
*/

#pragma once
#include "Item.h"
#include <time.h>
#include <cstdlib>

typedef struct graph* Graph;
typedef struct { int v; int w; } Edge;

static int pre[maxV];
static int cnt;

Edge EDGE(int, int);
Graph graphRand();
Graph graphInit(int);
void graphInsertE(Graph, Edge);
void graphRemoveE(Graph, Edge);
int graphEdges(Edge[], Graph);
Graph graphCopy(Graph);
void graphDestroy(Graph);


Edge EDGE(int v, int w)
{
	Edge e;
	e.v = v;
	e.w = w;
	return e;
}

Graph graphRand(int V, int E)					//随机生成一个简单图
{
	int i, j;
	double p = 2.0*E / V / (V - 1);
	Graph G = graphInit(V);
	srand((unsigned)time(NULL));
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (rand() < p*RAND_MAX)
				graphInsertE(G, EDGE(i, j));
		}
	}
	return G;
}



