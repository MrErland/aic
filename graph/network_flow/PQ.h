/*
function:优先队列,用于PFS
by:Erland
date:2017.8.22
*/

/********************索引堆实现**********************/
#pragma once
#include "Item.h"
struct Point{ int v; int wt; };
static int N, site[maxV + 1];				//保存每个节点在堆中的位置
static struct Point pq[maxV + 1];


bool less(Point a, Point b)
{
	return a.wt < b.wt;
}

void exch(Point a[],int i, int j)
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
	while (k > 1 && less(a[k / 2], a[k]))
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
		if (j < N && less(a[j], a[j + 1]))
			j++;
		if (less(a[j], a[k]))
			break;
		exch(a, k, j);
		k = j;
	}
}
void PQinsert(int wt[], int k)
{
	site[k] = ++N;
	pq[N].wt = wt[k];
	pq[N].v = k;
	fixUp(pq, N);
}

int PQdelemax()
{
	exch(pq, 1, N);
	fixDown(pq, 1, --N);
	return pq[N + 1].v;
}

void PQdec(int wt[], int w)			//改变权值，维护堆
{
	pq[site[w]].wt = wt[w];
	fixUp(pq, site[w]);
	fixDown(pq, site[w], N);
}

