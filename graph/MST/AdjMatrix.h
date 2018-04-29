/**
function:AdjMatrix
by:Erland
date:2017.8.9
*/

#pragma once
#ifdef AdjMatrix

#include "Graph.h"
#include <iostream>
#include <iomanip>

/*****************************邻接矩阵--无向有权图****************************/

struct graph{ int V; int E; double** adj; };		//邻接矩阵表示法

Graph graphInit(int V)
{
	Graph G = new graph;
	G->V = V;
	G->E = 0;
	G->adj = MatrixDou(V, V, initWT);
	return G;
}

void graphInsertE(Graph G, Edge e)
{
	int v = e.v, w = e.w;
	if (G->adj[v][w] == initWT)
		G->E++;
	G->adj[v][w] = e.wt;
	G->adj[w][v] = e.wt;
}

void graphRemoveE(Graph G, Edge e)
{
	int v = e.v, w = e.w;
	if (G->adj[v][w] != initWT)
		G->E--;
	G->adj[v][w] = initWT;
	G->adj[w][v] = initWT;
}

int graphEdges(Edge a[], Graph G)
{
	int v, w, E = 0;
	for (v = 0; v < G->V; v++)
	{
		for (w = v + 1; w < G->V; w++)
		{
			if (G->adj[v][w] != initWT)
				a[E++] = EDGE(v, w, G->adj[v][w]);
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
			if (G->adj[i][j] != 0)
				std::cout << std::setw(4) << j << " ";
		}
		std::cout << std::endl;
	}
}

#endif
