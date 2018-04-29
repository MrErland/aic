/**
function:Graph ADT
by:Erland
date:2017.8.11
*/

#pragma once
#include "Item.h"
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <sstream>

typedef struct graph* Graph;
typedef struct { int v; int w; int cap; int flow; int cost; } Edge;			//加入费用cost

static int pre[maxV];
static int cnt;
static int V;

Graph graphRand();
Graph graphInit(int);
void graphInsertE(Graph, Edge);
void graphRemoveE(Graph, Edge);
int graphEdges(Edge[], Graph);
Graph graphCopy(Graph);
void graphDestroy(Graph);


Edge EDGE(int v, int w, int cap, int flow, int cost)
{
	Edge e;
	e.v = v;
	e.w = w;
	e.cap = cap;
	e.flow = flow;
	e.cost = cost;
	return e;
}

Graph graphRand(int V, int E)						//随机生成一个简单图
{
	int i, j, s, t, k;
	double p = 2.0*E / V / (V - 1);
	Graph G = graphInit(V);
	srand((unsigned)time(NULL));					//固定随机性
	for (i = 0; i < V; i++)
	{
		for (j = i + 1; j < V; j++)
		{
			s = rand();
			if (s < p*RAND_MAX)
			{
				t = rand() % 99 + 1;
				k = rand() % 50 + 1;
				graphInsertE(G, EDGE(i, j, t, 0, k));		//cap:1~99  cost:1~50
			}			
		}
	}
	return G;
}

Graph graphReadFile()
{
	int E, i, u, v, cap, cost;
	std::ifstream Rgraph("graph.txt");
	if (Rgraph.is_open())
	{
		Rgraph >> V;
		Rgraph >> E;
	}
	Graph G = graphInit(V);
	for (i = 0; i < E; i++)
	{
		Rgraph >> u;
		Rgraph >> v;
		Rgraph >> cap;
		Rgraph >> cost;
		graphInsertE(G, EDGE(u, v, cap, 0, cost));
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
		{
			if (i == j)								//考虑自环
				t[i][j] = 0;
			else
				t[i][j] = val;
		}		
	}
	return t;
}

int **MatrixInt(int r, int c, int val)		//申请一块矩阵 并赋初值
{
	int i, j;
	int **t = new int*[r];
	for (i = 0; i < r; i++)
		t[i] = new int[c];
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (i == j)								//考虑自环
				t[i][j] = 0;
			else
				t[i][j] = val;
		}
	}
	return t;
}
