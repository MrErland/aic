/*
function:堆的数组实现
by:Erland
date:2017.7.7
*/

#pragma once
#include "sort.h"

void fixup(Item a[], int k)		//自底向上堆化
{
	while (k > 1 && less(a[k / 2], a[k]))
	{
		exch(a[k], a[k / 2]);
		k = k / 2;
	}
}

void fixdown(Item a[], int k, int N)	//自顶向下堆化
{
	int j;
	while (2 * k < N)
	{
		j = 2 * k;
		if (j < N && less(a[j], a[j + 1]))
			j++;
		if (!less(a[k], a[j]))
			break;
		exch(a[k], a[j]);
		k = j;
	}
}


