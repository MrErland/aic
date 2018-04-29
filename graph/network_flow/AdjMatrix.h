/**
function:AdjMatrix
by:Erland
date:2017.8.21
*/

#pragma once
#ifdef AdjMatrix

#include "Graph.h"
#include <iostream>
#include <iomanip>

/*****************************网络流邻接矩阵--有向有权图****************************/

struct graph{ int V; int E; int** cap; int** flow;};

Graph graphInit(int V)
{
	Graph G = new graph;
	G->V = V;
	G->E = 0;
	G->cap = MatrixInt(V, V, 0);
	G->flow = MatrixInt(V, V, 0);
	return G;
}

void graphInsertE(Graph G, Edge e)
{
	int v = e.v, w = e.w;
	if (G->cap[v][w] == 0)
		G->E++;
	G->cap[v][w] = e.cap;
	G->flow[v][w] = e.flow;
	G->cap[w][v] = -e.cap;
	G->flow[w][v] = -e.flow;
}

void graphRemoveE(Graph G, Edge e)
{
	int v = e.v, w = e.w;
	if (G->cap[v][w] != 0)
		G->E--;
	G->cap[v][w] = 0;
	G->flow[v][w] = 0;
	G->cap[w][v] = 0;
	G->flow[w][v] = 0;
}

int graphEdges(Edge a[], Graph G)
{
	int v, w, E = 0;
	for (v = 0; v < G->V; v++)
	{
		for (w = v + 1; w < G->V; w++)
		{
			if (G->cap[v][w] > 0)
				a[E++] = EDGE(v, w, G->cap[v][w], G->flow[v][w]);
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
			if (G->cap[i][j] != 0)
				std::cout << std::setw(4) << j << "-" << G->cap[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Graph graphReverse(Graph G)
{
	Graph R = graphInit(G->V);
	for (int i = 0; i < G->V; i++)
	{
		for (int j = 0; j < G->V; j++)
		{
			R->cap[j][i] = G->cap[i][j];
			R->flow[j][i] = G->flow[i][j];
			R->cost[j][i] = G->cost[i][j];
		}
	}
	return R;
}

#endif
