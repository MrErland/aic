/*
function:最小权值优先队列,用于PFS
by:Erland
date:2017.8.14
*/

/********************索引堆实现**********************/
#pragma once
#include "Item.h"
struct Point{ int v; double wt; };
static int N, site[maxV + 1];				//保存每个节点在堆中的位置
static struct Point pq[maxV + 1];


bool less(Point a, Point b)
{
	return a.wt < b.wt;
}

void exch(Point a[], int i, int j)
{
	int k = site[a[i].v];
	site[a[i].v] = site[a[j].v];
	site[a[j].v] = k;
	Point t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void PQinit()
{
	N = 0;
}

bool PQempty()
{
	return N == 0;
}

void fixUp(Point a[], int k)
{
	while (k > 1 && less(a[k], a[k / 2]))
	{
		exch(a, k, k / 2);
		k = k / 2;
	}
}
void fixDown(Point a[], int k, int N)
{
	int j;
	while (2 * k < N)
	{
		j = 2 * k;
		if (j < N && less(a[j + 1], a[j]))
			j++;
		if (less(a[k], a[j]))
			break;
		exch(a, k, j);
		k = j;
	}
}
void PQinsert(double wt[], int k)
{
	site[k] = ++N;
	pq[N].wt = wt[k];
	pq[N].v = k;
	fixUp(pq, N);
}

int PQdelemin()
{
	exch(pq, 1, N);
	fixDown(pq, 1, --N);
	return pq[N + 1].v;
}

void PQdec(double wt[], int w)			//改变权值，维护堆
{
	pq[site[w]].wt = wt[w];
	fixUp(pq, site[w]);
	fixDown(pq, site[w], N);
}

