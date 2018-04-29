/*
function:跳跃表
by:Erland
date:2017.7.21
*/

#pragma once
#include <stdlib.h>
#include "Item.h"

#define lgNmax 5
static int N, lgN;

link_sk NEW(Item item, int k)
{
	int i;
	link_sk x = new SKnode;
	x->next = (link_sk*)malloc(sizeof(link_sk)*k);
	x->item = item;
	x->sz = k;
	for (i = 0; i < k; i++)
		x->next[i] = z_sk;
	return x;
}

void init_SK()	//SkipList init
{
	N = 0;
	lgN = 0;
	z_sk = NEW(NULLItem, 0);
	head_sk = NEW(NULLItem, lgNmax + 1);
	tail_sk = NEW(INF, lgNmax + 1);				//增加跳跃表尾的标识
	for (int i = 0; i < lgNmax + 1; i++)		//初始表头指向表尾
		head_sk->next[i] = tail_sk;
}


Item searchS(link_sk t, Key v, int k)
{
	if (t == z_sk)
		return NULLItem;
	if (equ(v, key(t->item)))
		return t->item;
	if (less(v, key(t->next[k]->item)))
	{
		if (k == 0)
			return NULLItem;
		return searchS(t, v, k - 1);
	}
	return searchS(t->next[k], v, k);
}
Item search_SK(Key v)
{
	return searchS(head_sk, v, lgN);
}


int randx()
{
	int i, j, t = rand();
	for (i = 1, j = 2; i < lgNmax; i++, j += j)
	{
		if (t > RAND_MAX / j)
			break;
	}
	if (i > lgN) lgN = i;
	return i;
}
void insertS(link_sk t, link_sk x, int k)
{
	Key v = key(x->item);
	if (less(v, key(t->next[k]->item)))
	{
		if (k < x->sz)
		{
			x->next[k] = t->next[k];
			t->next[k] = x;
		}
		if (k == 0)
			return;
		insertS(t, x, k - 1);
		return;
	}
	insertS(t->next[k], x, k);
}
void insert_SK(Item item)
{
	insertS(head_sk, NEW(item, randx()), lgN);
	N++;
}


void deleS(link_sk t, Key v, int k)
{
	link_sk x = t->next[k];
	if (!less(key(x->item), v))
	{
		if (equ(v, key(x->item)))
		{
			t->next[k] = x->next[k];
			if (k == 0)
			{
				delete x;
				return;
			}
		}
		deleS(t, v, k - 1);
		return;
	}
	deleS(t->next[k], v, k);
}
void delete_SK(Key v)
{
	deleS(head_sk, v, lgN);
	N--;
}
