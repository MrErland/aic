/*
function:有向图的闭包求解
by:Erland
date:2017.8.3
*/

#ifdef AdjMatrix
#include "AdjMatrix.h"

//布尔矩阵相乘法
void graphTC(Graph G)
{
	int i, s, t;
	G->tc = MatrixInt(G->V, G->V, 0);
	for (s = 0; s < G->V; s++)
	{
		for (t = 0; t < G->V; t++)
			G->tc[s][t] = G->adj[s][t];
	}

	for (s = 0; s < G->V; s++)
		G->tc[s][s] = 1;

	for (i = 0; i < G->V; i++)
	{
		for (s = 0; s < G->V; s++)
		{
			if (G->tc[s][i] == 1)
			{
				for (t = 0; t < G->V; t++)
				{
					if (G->tc[i][t] == 1)
						G->tc[s][t] = 1;
				}
			}
		}
	}
}
int graphReach(Graph G, int s, int t)		//常数时间内查询
{
	return G->tc[s][t];
}


#endif

#ifdef AdjList
#include "AdjList.h"

//深度优先搜索法
void dfsTC(Graph G, Edge e)
{
	link t;
	G->tc[e.v][e.w] = 1;
	for (t = G->adj[e.w]; t != NULL; t = t->next)
	{
		if (G->tc[e.v][t->v] == 0)			//路径长度变为2
			dfsTC(G, EDGE(e.v, t->v));
	}
}


void graphTC(Graph G, Edge e)				//时间复杂度V(V+E)
{
	int v, w;
	G->tc = MatrixInt(G->V, G->V, 0);
	for (v = 0; v < G->V; v++)
		dfsTC(G, EDGE(v, v));
}
int graphReach(Graph G, int s, int t)		//常量时间查询
{
	return G->tc[s][t];
}


#endif
