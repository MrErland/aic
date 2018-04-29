/*
function:基本路径求解
by:Erland
date:2017.7.25
*/

#pragma once 

#include "Item.h"
#include "Stack.h"
#include "AdjMatrix.h"
#include "AdjList.h"
#include <iostream>

#ifdef AdjMatrix	

//简单路径DFS搜索----AdjMatrix
static int visited[maxV];
bool pathR(Graph G, int v, int w)
{
	int t;
	if (v == w)
		return true;
	visited[v] = 1;
	for (t = 0; t < G->V; t++)
	{
		if (G->adj[v][t] == 1 && visited[t] == 0 && pathR(G, t, w))
			return true;
	}
	return false;
}
bool graphPath(Graph G, int v, int w)
{
	int t;
	for (t = 0; t < G->V; t++)
		visited[t] = 0;
	return pathR(G, v, w);
}


//欧拉路径存在性
bool graphPathEuler(Graph G, int v, int w)
{
	int s, t;
	s = graphDeg(G, v);
	t = graphDeg(G, w);
	if (v != w)
	{
		if ((s + t) % 2 != 0 || (s % 2 == 0 && t % 2 == 0))
			return 0;
	}
	else if (s % 2 != 0 || t % 2 != 0)
			return 0;
	for (t = 0; t < G->V; t++)
	{
		if (t != v && t != w && (graphDeg(G, t) % 2) != 0)
			return 0;
	}
	return 1;
}

#endif // AdjMatrix


#ifdef AdjList
	
//查找欧拉路径
int path(Graph G, int v, Pstack s)
{
	int w;
	for (; G->adj[v] != NULL; v = w)
	{
		pushStack(s, v);
		w = G->adj[v]->v;
		graphRemoveE(G, EDGE(v, w));
	}
	return v;
}
void pathEuler(Graph G, int v, int w)
{
	Pstack s = initStack(G->E);
	std::cout << w;
	while (path(G, v, s) == v && !emptyStack(s))
	{
		v = popStack(s);
		std::cout << "-" << v;
	}
	std::cout << std::endl;
}

		
#endif
