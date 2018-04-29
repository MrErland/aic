/*
function:MST问题的Kruskal算法
by:Erland
date:2017.8.10
*/

//可用于邻接表和邻接矩阵,返回边数组mst[]
#pragma once
#include "AdjList.h"
#include "AdjMatrix.h"
#include "UF.h"

//基本快速排序法
void exchange(Edge *a, Edge *b)
{
	Edge *t = a;
	a = b;
	b = t;
}

int partition(Edge *a, int l, int r)
{
	int i = l - 1, j = r;
	double v = a[r].wt;					//最右侧作为初始元素
	while (1)
	{
		while (a[++i].wt < v);
		while (v < a[--j].wt)
		{
			if (j == l)
				break;
		}
		if (i >= j)
			break;
		exchange(&a[i], &a[j]);
	}
	exchange(&a[i], &a[r]);
	return i;
}

void quickSort(Edge *a, int l, int r)
{
	int i;
	if (r <= l)
		return;
	i = partition(a, l, r);
	quickSort(a, l, i - 1);
	quickSort(a, i + 1, r);
}



void GraphMSTK(Graph G, Edge mst[])
{
	int i, k;
	Edge a[maxE];
	int E = graphEdges(a, G);			//将图转换为边数组
	quickSort(a, 0, E - 1);				//将边数组按照权值排序,可用最小堆优化
	UFinit(G->V);
	for (i = 0, k = 0; i < E && k < G->V; i++)
	{
		if (!UFfind(a[i].v, a[i].w))	//判断是否形成环,十分巧妙
		{
			UFunion(a[i].v, a[i].w);
			mst[k++] = a[i];
		}
	}
}
