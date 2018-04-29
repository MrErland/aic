/*
function:DAG的传递闭包——DFS、动态规划
by:Erland
date:2017.8.9
*/

#ifdef AdjMatrix

#include "AdjMatrix.h"
#define Dag Graph

void dfsTcR(Dag D, Edge e)
{
	int u, i, v = e.w;
	pre[v] = cnt++;
	for (u = 0; u < D->V; u++)
	{
		if (D->adj[v][u] != 0)
		{
			D->tc[v][u] = 1;
			if (pre[u]>pre[v])
				continue;
			if (pre[u] == -1)
				dfsTcR(D, EDGE(v, u));
			for (i = 0; i < D->V; i++)
			{
				if (D->tc[u][i] == 1)
					D->tc[v][i] = 1;
			}
		}
	}
}


void DagTC(Dag D)						//预处理
{
	int v;
	cnt = 0;
	D->tc = MatrixInt(D->V, D->V, 0);
	for (v = 0; v < D->V; v++)
		pre[v] = -1;
	for (v = 0; v < D->V; v++)
	{
		if (pre[v] == -1)
			dfsTcR(D, EDGE(v, v));
	}
}

int DagReach(Dag D, int s, int t)		//查询
{
	return D->tc[s][t];
}

#endif
