/*
function:基本排序方法
by:Erland
date:2017.7.3
*/

#include "sort.h"

void getrand(Item *a, int N)
{
	for (int i = 0; i < N; i++) a[i] = Item(SIZE_NUM * (1.0 * rand() / RAND_MAX));
}

void selection(Item *a, int l, int r)		//选择排序
{
	int i, j, min;
	for (i = l; i < r; i++)
	{
		min = i;
		for (j = i + 1; j <= r; j++)
		{
			if (less(a[j], a[min]))
				min = j;
		}
		exch(a[i], a[min]);
	}
}

void insertion(Item *a, int l, int r)	//插入排序
{
	int i, j;
	for (i = r; i > l; i--)
		compexch(a[i - 1], a[i]);		//最小的元素放在第一位
	for (i = i + 2; i <= r; i++)
	{
		j = i;
		Item v = a[i];
		while (less(v, a[j - 1]))
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
	}
}

void bubble(Item *a, int l, int r)		//冒泡排序
{
	int i,j;
	for (i = l; i < r; i++)
	{
		for (j = r; j > i; j--)
		{
			compexch(a[j - 1], a[j]);
		}
	}
}

void distCount(int *a, int l, int r)		//关键字索引算法,空间利用率不高,时间效率为线性
{
	int i, j, cnt[M];
	int b[SIZE_TEST];			//l == 0,b[SIZE_TEST+l]
	for (j = 0; j < M; j++)			//初始化为0
		cnt[j] = 0;
	for (i = l; i <= r; i++)		//将各个元素累计
		cnt[a[i] + 1]++;
	for (j = 1; j < M; j++)			//计算小于元素所有元素的数目
		cnt[j] += cnt[j - 1];

	for (i = l; i <= r; i++)		//将各个元素放在中间数组的适当位置
		b[cnt[a[i]]++] = a[i];
	for (i = l; i <= r; i++)		//排序好的中间数组元素移回原数组
		a[i] = b[i - l];
}
