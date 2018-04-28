/*
function：归并排序
by:Erland
data:2017.7.6
*/

#ifndef _merge_sort_
#define _merge_sort_

#include "sort.h"
#define Border 10
#define maxN 25000
#define min(A, B) (A < B) ? A : B

void mergeAB(Item c[], Item a[], int N, Item b[], int M)	//标准归并,A B有序
{
	for (int i = 0, j = 0, k = 0; k < N + M; k++)
	{
		if (i == N)
		{
			c[k] = b[j++];
			continue;
		}
		if (i == M)
		{
			c[k] = a[i++];
			continue;
		}
		c[k] = (less(a[i], b[j])) ? a[i++] : b[j++];
	}
}

void merge(Item a[], int l, int m, int r)	//抽象原位归并,减少循环内的判断开销,但是数组增大开销
{
	Item aux[maxN];
	int i, j, k;
	for (i = m + 1; i > l; i--)		//构造新的数组
		aux[i - 1] = a[i - 1];
	for (j = m; j < r; j++)
		aux[r + m - j] = a[j + 1];

	for (k = l; k <= r; k++)		//j==r,i==l
	{
		if (less(aux[j], aux[i]))
			a[k] = aux[j--];
		else
			a[k] = aux[i++];
	}
}

void mergeSort(Item a[], int l, int r)	//1.自顶向下的归并排序
{
	int m = (l + r) / 2;
	if (r <= l) return;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, m, r);
}


void mergeSortABr(Item a[], Item b[], int l, int r)
{
	int m = (l + r) / 2;
	if (r - l <= Border)
	{
		insertion(a, l, r);
		return;
	}
	mergeSortABr(b, a, l, m);
	mergeSortABr(b, a, m + 1, r);
	mergeAB(a + 1, b + 1, m - l + 1, b + m + 1, r - m);
}
void mergeSortAB(Item a[], int l, int r)		//2.小文件中断,没有复制数组的归并排序
{
	int i;
	Item aux[maxN];
	for (i = l; i <= r; i++)
		aux[i] = a[i];
	mergeSortABr(a, aux, l, r);
}


void mergeSortBU(Item a[], int l, int r)	//3.自底向上的归并排序
{
	for (int m = 1; m <= r - l; m *= 2)
	{
		for (int i = l; i <= r - m; i += m + m)
			merge(a, i, i + m - 1, min(i + m + m - 1, r));
	}
}



listN mergeList(listN a, listN b)	//链表实现归并
{
	listNode head;
	listN c = &head;			//需要新建一个链表，消耗空间
	while (a != NULL && b != NULL)
	{
		if (less(a->item, b->item))
		{
			c->next = a;
			c = a;
			a = a->next;
		}
		else{
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	c->next = (a == NULL) ? b : a;
	return head.next;
}

listN mergeSortList(listN c)	//1.自顶向下归并排序
{
	listN a, b;
	if (c == NULL || c->next == NULL) return c;
	a = c;
	b = c->next;
	while (b != NULL && b->next != NULL)	//找到链表的中点c
	{
		c = c->next;
		b = b->next->next;
	}
	b = c->next;
	c->next = NULL;
	return mergeList(mergeSortList(a), mergeSortList(b));
}
