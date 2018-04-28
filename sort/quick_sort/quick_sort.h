/*
function：快速排序实现及改进
by:Erland
data:2017.7.5
*/

#ifndef _quick_sort_
#define _quick_sort_

#include "sort.h"
#include <stack>

int partition(Item *a, int l, int r)
{
	int i = l - 1, j = r;
	Item v = a[r];					//最右侧作为初始元素
	while (1)
	{
		while (less(a[++i], v));
		while (less(v, a[--j]))
		{
			if (j == l) break;
		}
		if (i >= j) break;
		exch(a[i], a[j]);
	}
	exch(a[i], a[r]);
	return i;
}

void quickSort_1(Item *a, int l, int r)		//基本快速排序算法
{
	int i;
	if (r <= l) return;
	i = partition(a, l, r);
	quickSort_1(a, l, i - 1);
	quickSort_1(a, i + 1, r);
}

void quickSort_2(Item *a, int l, int r)		//非递归形式的快速排序
{
	int i;
	std::stack<Item> s;
	s.push(r);
	s.push(l);
	while (!s.empty())
	{
		l = s.top(); s.pop();
		r = s.top(); s.pop();
		if (r <= l) continue;
		i = partition(a, l, r);
		if (i - l > r - i)			//长度大的一侧先入栈
		{	
			s.push(i - 1);
			s.push(l);
			s.push(r);
			s.push(i + 1);
		}
		else{
			s.push(r);
			s.push(i + 1);
			s.push(i - 1);
			s.push(l);
		}
	}
}


#define Border 10
void quickSort_3(Item *a, int l, int r)		
{
	int i;
	if (r - l <= Border)				//忽略小文件
		return;
	exch(a[(l + r) / 2], a[r - 1]);		//三者取中
	compexch(a[l], a[r - 1]);
	compexch(a[l], a[r]);
	compexch(a[r - 1], a[r]);			// l < r-1 < r
	i = partition(a, l, r - 1);
	quickSort_3(a, l, i - 1);
	quickSort_3(a, i + 1, r);
}
void advanced_1(Item *a, int l, int r)	//改进后的快速排序：三者取中、小文件的阈值M
{
	quickSort_3(a, l, r);				
	insertion(a, l, r);					//小文件用插入排序完成
}

void advanced_2(Item *a, int l, int r)	//改进后的快速排序：三路划分
{
	int i, j, k, p, q;
	Item v = a[r];
	if (r <= l) return;
	i = l - 1; j = r;
	p = l - 1; q = r;
	while (1)
	{
		while (less(a[++i], v));
		while (less(v, a[--j]))
		{
			if (j == l) break;
		}
		if (i >= j) break;
		exch(a[i], a[j]);
		if (a[i] == v)
		{
			p++;
			exch(a[p], a[i]);
		}
		if (v == a[j])
		{
			q--;
			exch(a[q], a[j]);
		}
	}
	exch(a[i], a[r]);
	j = i - 1;
	i = i + 1;
	for (k = l; k < p; k++, j--) exch(a[k], a[j]);
	for (k = r - 1; k > q; k--, i++) exch(a[k], a[i]);
	advanced_2(a, l, j);
	advanced_2(a, i, r);
}

#endif
