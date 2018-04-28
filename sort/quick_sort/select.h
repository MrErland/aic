/*使用"快速排序法"解决"选择K"问题,"选择排序法"适用于K较小的情况*/

#ifndef _select_k_
#define _select_k_

#include "quick_sort.h"

void select1(Item a[], int l, int r, int k)	//求l~r之间第K小的元素 a[K+l-1]
{
	int i, t;
	if (r <= l) return;
	i = partition(a, l, r);
	t = i - l + 1;
	if (k < t)
		select1(a, l, i - 1, k);
	if (k > t)
		select1(a, i + 1, r, k);
}

void select2(Item a[], int l, int r, int k)	//非递归实现
{
	while (r > l)
	{
		int i = partition(a, l, r);
		int t = i - l + 1;
		if (t >= k)
			r = i - 1;
		if (t <= k)
			l = i + 1;
	}
}

#endif
