/*
function:堆排序
by:Erland
date:2017.7.7
*/

#pragma once
#include "priority_queue.h"
#include "heap.h"
#define NUM 250000

void prioqueSort(Item a[], int l, int r)	//优先队列排序
{
	int k;
	initProque_2(NUM);
	for (k = l; k <= r; k++)
		insertProque_2(a[k]);
	for (k = r; k >= l; k--)
		a[k] = deleProque_2();
}

void heapSort(Item a[], int l, int r)	//堆排序
{
	int k, n = r - l + 1;
	Item* pq = a + l - 1;
	for (k = n / 2; k >= 1; k--)	//构建堆有序
		fixdown(pq, k, n);
	while (n > 1)
	{
		exch(pq[1], pq[n]);
		fixdown(pq, 1, --n);
	}
}
