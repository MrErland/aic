/**
function:ADT of AdjMatrix
by:Erland
date:2017.8.1
*/

#pragma once
#ifdef AdjMatrix

#include "Graph.h"
#include <iostream>
#include <iomanip>

/*****************************邻接矩阵--有向图****************************/

struct graph{ int V; int E; int** adj; int** tc; };		//邻接矩阵表示法

Graph graphInit(int V)
{
	Graph G = new graph;
	G->V = V;
	G->E = 0;
	G->adj = MatrixInt(V, V, 0);
	return G;
}

void graphInsertE(Graph G, Edge e)
{
	int v = e.v, w = e.w;
	if (G->adj[v][w] == 0)
		G->E++;
	G->adj[v][w] = 1;
}

void graphRemoveE(Graph G, Edge e)
{
	int v = e.v, w = e.w;
	if (G->adj[v][w] == 1)
		G->E--;
	G->adj[v][w] = 0;
}

int graphEdges(Edge a[], Graph G)
{
	int v, w, E = 0;
	for (v = 0; v < G->V; v++)
	{
		for (w = v + 1; w < G->V; w++)
		{
			if (G->adj[v][w] == 1)
				a[E++] = EDGE(v, w);
		}
	}
	return E;
}

void graphShow(Graph G)
{
	int i, j;
	std::cout << G->V << " Vertices, " << G->E << " Edges." << std::endl;
	for (i = 0; i < G->V; i++)
	{
		std::cout << std::setw(4) << i << ":";
		for (j = 0; j < G->V; j++)
		{
			if (G->adj[i][j] == 1)
				std::cout << std::setw(4) << j << " ";
		}
		std::cout << std::endl;
	}
}

int graphDegOut(Graph G, int v)		//计算顶点的出度 时间复杂度V
{
	if (G->V - 1 < v)
		return 0;
	int i, n = 0;
	for (i = 0; i < G->V; ++i)
	{
		if (G->adj[v][i] != 0)
			++n;
	}
	return n;
}

#endif
