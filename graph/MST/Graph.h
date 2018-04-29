/**
function:Graph ADT
by:Erland
date:2017.8.9
*/

#pragma once
#include "Item.h"
#include <time.h>
#include <cstdlib>

typedef struct graph* Graph;
typedef struct { int v; int w; double wt; } Edge;

static int pre[maxV];
static int cnt;

Edge EDGE(int, int, double);
Graph graphRand();
Graph graphInit(int);
void graphInsertE(Graph, Edge);
void graphRemoveE(Graph, Edge);
int graphEdges(Edge[], Graph);
Graph graphCopy(Graph);
void graphDestroy(Graph);


Edge EDGE(int v, int w, double wt)
{
	Edge e;
	e.v = v;
	e.w = w;
	e.wt = wt;
	return e;
}

Graph graphRand(int V, int E)						//随机生成一个简单图
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
				graphInsertE(G, EDGE(i, j, rand() % (999 - 1) + initWT + 1));
		}
	}
	return G;
}

double **MatrixDou(int r, int c, double val)		//申请一块矩阵 并赋初值
{
	int i, j;
	double **t = new double*[r];
	for (i = 0; i < r; i++)
		t[i] = new double[c];
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			t[i][j] = val;	
	}
	return t;
}

