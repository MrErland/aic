/*
function:所有对最短路径,包括预处理函数及查询函数
by:Erland
date:2017.8.15
*/

#pragma once 
#include "AdjList.h"
#include "AdjMatrix.h"
#include "Dijkstra.h"

//适用于稀疏图
void GraphSPAllD(Graph G)
{
	int v, w;
	int st[maxV];
	double wt[maxV + 1];
	Graph R = graphReverse(G);
	G->dist = MatrixDou(G->V, G->V, maxWT);		//最短路径长度
	G->path = MatrixInt(G->V, G->V, G->V);		//最短路径下一个结点
	for (v = 0; v < G->V; v++)
	{
		GraphSPTDij(R, st, wt, v);				//每个结点Dijkstra
		for (w = 0; w < G->V; w++)
		{
			G->dist[w][v] = wt[w];				//注意是逆图
			if (st[w] != -1)
				G->path[w][v] = st[w];
		}
	}
}

double GraphSPDist(Graph G, int s, int t)
{
	return G->dist[s][t];
}
int GraphSPPath(Graph G, int s, int t)
{
	return G->path[s][t];
}


//适用于稠密图--Floyd
#ifdef AdjMatrix

void GraphSPAllF(Graph G)
{
	int i, s, t;
	double **d = MatrixDou(G->V, G->V, maxWT);		//dist
	int **p = MatrixInt(G->V, G->V, G->V);			//path
	for (s = 0; s < G->V; s++)
	{
		for (t = 0; t < G->V; t++)
		{
			if ((d[s][t] = G->adj[s][t]) < maxWT)
				p[s][t] = t;
		}
	}
	for (i = 0; i < G->V; i++)
	{
		for (s = 0; s < G->V; s++)
		{
			if (d[s][i] < maxWT)
			{
				for (t = 0; t < G->V; t++)
				{
					if (d[s][t] > d[s][i] + d[i][t])
					{
						p[s][t] = p[s][i];
						d[s][t] = d[s][i] + d[i][t];
					}
				}
			}
		}
	}
	G->dist = d;
	G->path = p;
}

#endif
