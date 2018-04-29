/*
function:链地址法,单链表无序:插入速度较快，搜索失败的时间增加。
by:Erland
date:2017.7.24
*/

#pragma once
#include "Item.h"
#include "Hash.h"
#include <iostream>

typedef struct STnode *link;
static link *heads, z;
static int N_ST, M_ST;		//N_ST = 数据数目 M_ST = 单链表个数
struct STnode{
	Item item;
	link next;
};

static link NEW(Item item, link next)
{
	link x = new STnode;
	x->item = item;
	x->next = next;
	return x;
}

void initST(int max)
{
	int i;
	N_ST = 0;
	M_ST = max / 5;
	heads = new link[M_ST];
	z = NEW(NULLItem, NULL);
	for (i = 0; i < M_ST; i++)
		heads[i] = z;
}

int countST()
{
	return N_ST;
}

Item search(link t, Key v)
{
	if (t == NULL)
		return NULLItem;
	if (equ(key(t->item), v))
		return t->item;
	return search(t->next, v);
}
Item searchST(Key v)
{
	return search(heads[hash(v, M_ST)], v);
}

void insertST(Item item)		
{
	int i = hash(key(item), M_ST);
	heads[i] = NEW(item, heads[i]);
	N_ST++;
}

link dele(link t, Item item)
{
	if (t == z)
		return t;
	link h = t, r = t;
	if (t->item == item)
	{
		h = t->next;
		delete t;
		return h;
	}
	t = t->next;
	while (t != z)
	{
		if (t->item == item)
		{
			h->next = t->next;
			delete t;
			return r;
		}
		t = t->next;
		h = h->next;
	}
	return r;
}
void deleST(Item item)
{
	int i = hash(key(item), M_ST);
	heads[i] = dele(heads[i], item);
}
