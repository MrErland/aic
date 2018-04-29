/*
function:MST问题的Boruvka算法
by:Erland
date:2017.8.11
*/

//可用于邻接表和邻接矩阵,返回边数组mst[]
#pragma once
#include "AdjList.h"
#include "AdjMatrix.h"
#include "UF.h"


void GraphMSTB(Graph G, Edge mst[])
{
	int h, i, j, k, v, w, N, P = 0;
	Edge e, nn[maxV], a[maxV];
	int E = graphEdges(a, G);

	for (UFinit(G->V); E != 0; E = N)
	{
		for (k = 0; k < G->V; k++)
			nn[k] = EDGE(G->V, G->V, maxWT);	//每个树分支最邻近边
		for (h = 0, N = 0; h < E; h++)
		{
			i = find(a[h].v);
			j = find(a[h].w);
			if (i == j)
				continue;
			if (a[h].wt < nn[i].wt)
				nn[i] = a[h];
			if (a[h].wt < nn[j].wt)
				nn[j] = a[h];
			a[N++] = a[h];				//a[]边数组被重新赋值为非树边,外部每循环一次,N减半
		}
		for (k = 0; k < G->V; k++)
		{
			e = nn[k];
			v = e.v;
			w = e.w;
			if (v != G->V && !UFfind(v, w))
			{
				UFunion(v, w);
				mst[P++] = e;			//修改了P
			}
		}
	}
}
