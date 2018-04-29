/*
function:DFS Implement
by:Erland
date:2017.7.26
*/


#pragma once
#ifdef AdjMatrix
#include "AdjMatrix.h"

//搜索图的顶点
void DFS(Graph G, Edge e)
{
	int t, w = e.w;
	pre[w] = cnt++;
	for (t = 0; t < G->V; t++)
	{
		if (G->adj[w][t] != 0 && pre[t] == -1)
			DFS(G, EDGE(w, t));
	}
}

#endif

#ifdef AdjList
#include "AdjList.h"
#include <iostream>

//搜索图的顶点
void DFS(Graph G, Edge e)
{
	link t;
	int w = e.w;
	pre[w] = cnt++;
	for (t = G->adj[w]; t != NULL; t = t->next)
	{
		if (pre[t->v] == -1)
			DFS(G, EDGE(w, t->v));
	}
}
	

/*************************图的连通性*************************/
void dfsRcc(Graph G, int v, int id)			//DFS
{
	link t;
	G->cc[v] = id;
	for (t = G->adj[v]; t != NULL; t = t->next)
	{
		if (G->cc[t->v] == -1)
			dfsRcc(G, t->v, id);
	}
}
int graphRcc(Graph G)						//1.计算连通分支----线性复杂度
{
	int v, id = 0;
	G->cc = new int[G->V];
	for (v = 0; v < G->V; v++)
		G->cc[v] = -1;
	for (v = 0; v < G->V; v++)
	{
		if (G->cc[v] == -1)
			dfsRcc(G, v, id++);
	}
	return id;
}
bool graphConnect(Graph G, int s, int t)	//2.判断连通性----常数复杂度
{
	return G->cc[s] == G->cc[t];
}



/*************************双向欧拉回路*************************/
void dfsEuler(Graph G, Edge e)
{
	link t;
	std::cout << "-" << e.w;
	pre[e.w] = cnt++;								//需要初始化pre[]
	for (t = G->adj[e.w]; t != NULL; t = t->next)
	{
		if (pre[t->v] == -1)
			dfsEuler(G, EDGE(e.w, t->v));
		else if (pre[t->v] < pre[e.v])
			std::cout << "-" << t->v << "-" << e.w;
	}
	if (e.v != e.w)
		std::cout << "-" << e.v;
	else
		std::cout << '\n';
}



/*************************割边--边连通性*************************/
static int low[maxV];
static int bcnt;
void bridge(Graph G, Edge e)
{
	link t;
	int v, w = e.w;
	pre[w] = cnt++;						//pre[]初始化
	low[w] = pre[w];					//low[]初始化
	for (t = G->adj[w]; t != NULL; t = t->next)
	{
		if (pre[v = t->v] == -1)
		{
			bridge(G, EDGE(w, v));
			if (low[w] > low[v])
				low[w] = low[v];
			if (low[v] == pre[v])
			{
				bcnt++;
				std::cout << w << "-" << v << std::endl;
			}
		}
		else if (v != e.v && low[w] > pre[v])
			low[w] = pre[v];
	}
}
int graphBridge(Graph G, Edge e)
{
	int v;
	for (v = 0; v < G->V; v++)
		pre[v] = low[v] = -1;
	cnt = bcnt = 0;
	bridge(G, e);
	return bcnt;
}


#endif


/*************************搜索整个图的顶点****************************/
void graphSearchDFS(Graph G)
{
	int v;
	cnt = 0;
	for (v = 0; v < G->V; v++)
		pre[v] = -1;
	for (v = 0; v < G->V; v++)
	{
		if (pre[v] == -1)
			DFS(G, EDGE(v, v));
	}
}


