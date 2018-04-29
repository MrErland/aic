/*
function:合并查找ADT
by:Erland
date:2017.8.10
*/

#pragma once
#include "Item.h"
static int *id, *sz;

void UFinit(int N)
{
	int i;
	id = new int[N];
	sz = new int[N];
	for (i = 0; i < N; i++)
	{
		id[i] = i;
		sz[i] = 1;
	}
}

int find(int x)
{
	int i = x;
	while (i != id[i])
		i = id[i];
	return i;
}

bool UFfind(int p, int q)
{
	return find(p) == find(q);
}

void UFunion(int p, int q)
{
	int i = find(p);
	int j = find(q);
	if (i == j)
		return;
	if (sz[i] < sz[j])
	{
		id[i] = j;
		sz[j] += sz[i];
	}
	else
	{
		id[j] = i;
		sz[i] += sz[j];
	}
}
