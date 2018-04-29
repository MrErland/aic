/*
function:散列的线性探测法,双重散列法
by:Erland
date:2017.7.24
*/

#pragma once
#include "Item.h"
#include "Hash.h"


//线性探测法

static Item *st;
static int N_D, M_D;	//M > N

void init_Det(int max)
{
	N_D = 0;
	M_D = 1 * max;		//M = 2 * max
	st = new Item[M_D];
	for (int i = 0; i < M_D; i++) st[i] = NULLItem;
}

int count_Det()
{
	return N_D;
}

void insert_Det(Item item)
{
	Key v = key(item);
	int i = hash(v, M_D);
	while (key(st[i]) != NULLItem)
		i = (i + 1) % M_D;
	st[i] = item;
	N_D++;
}

Item search_Det(Key v)
{
	int i = hash(v, M_D);
	while (key(st[i]) != NULLItem)
	{
		if (equ(v, key(st[i])))
			return st[i];
		else
			i = (i + 1) % M_D;
	}
	return NULLItem;
}

void delete_Det(Item item)
{
	int j, i = hash(key(item), M_D);
	Item v;
	while (key(st[i]) != NULLItem)
	{
		if equ(key(item), key(st[i]))
			break;
		else
			i = (i + 1) % M_D;
	}
	if (key(st[i]) == NULLItem)		//不存在删除元素
		return;
	st[i] = NULLItem;
	N_D--;
	for (j = i + 1; key(st[j]) != NULLItem; j = (j + 1) % M_D, N_D--)	//删除后重新散列
	{
		v = st[j];
		st[i] = NULLItem;
		insert_Det(v);
	}
}


//双重散列表

int hash_Two(int v, int M)
{
	return (v % 97) + 1;
}

void insert_Two(Item item)
{
	Key v = key(item);
	int i = hash(v, M_D);
	int k = hash_Two(v, M_D);
	while (key(st[i]) != NULLItem)
		i = (i + k) % M_D;
	st[i] = item;
	N_D++;
}

Item search_Two(Key v)
{
	int i = hash(v, M_D);
	int k = hash_Two(v, M_D);
	while (key(st[i]) != NULLItem)
	{
		if (equ(v, key(st[i])))
			return st[i];
		else
			i = (i + k) % M_D;
	}
	return NULLItem;
}
