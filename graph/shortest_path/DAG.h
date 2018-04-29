/*
function:无环有向图中的最长和最短路径问题,可处理负权边
by:Erland
date:2017.8.16
*/

#pragma once 
#ifdef AdjList
#include "TS.h"

static int ts[maxV];
void DagLPT(Graph G, int s, int st[], double wt[])	//wt[]保存最长路径长度，初始化为0
{
	int i, v, w;
	link t;
	DagTS(G, ts);							//拓扑排序后结点顺序保存在ts[]中
	for (v = ts[i = 0]; i < G->V; v = ts[i++])
	{
		for (t = G->adj[v]; t != NULL; t = t->next)
		{
			if (wt[w = t->v] < wt[v] + t->wt)
			{
				wt[w] = wt[v] + t->wt;
				st[w] = v;
			}
		}
	}

}


//无环网中的所有最短路径--逆拓扑排序
void SPdfsR(Graph G, int s)
{
	link u;
	int i, t;
	double wt;
	int **p = G->path;
	double **d = G->dist;
	for (u = G->adj[s]; u != NULL; u = u->next)
	{
		t = u->v;
		wt = u->wt;
		if (d[s][t] > wt)
		{
			d[s][t] = wt;
			p[s][t] = t;
		}
		if (d[t][t] == maxWT)
			SPdfsR(G, t);
		for (i = 0; i < G->V; i++)
		{
			if (d[t][i] < maxWT && d[s][i] > wt + d[t][i])
			{
				d[s][i] = wt + d[t][i];
				p[s][i] = t;
			}
		}
	}
}
void DagSPAll(Graph G)
{
	int v;
	G->dist = MatrixDou(G->V, G->V, maxWT);
	G->path = MatrixInt(G->V, G->V, G->V);
	for (v = 0; v < G->V; v++)
	{
		if (G->dist[v][v] == maxWT)					//?，建立图时自环细节
			SPdfsR(G, v);
	}
}



#endif
