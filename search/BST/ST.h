/*
function:符号表的数组,链表实现
by:Erland
date:2017.7.10
*/

#include "Item.h"
#include <iostream>


//关键字索引数组搜索
static Item *st_key;
static int M = maxKey;

void initST_key(int maxN)
{
	int i;
	st_key = new Item[M + 1]();
	for (i = 0; i <= M; i++)
		st_key[i] = NULLItem;
}

int countST_key()
{
	int i, N_1 = 0;
	for (i = 0; i < M; i++)
	{
		if (st_key[i] != NULLItem) N_1++;
	}
	return N_1;
}

void insertST_key(Item item)
{
	st_key[key(item)] = item;
}

Item searchST_key(Key v)
{
	return st_key[v];
}

void deleST_key(Item item)
{
	st_key[key(item)] = NULLItem;
}

Item selectST_key(int k)
{
	int i;
	for (i = 0; i < M; i++)
	{
		if (st_key[i] != NULLItem)
		{
			if (k-- == 0)
				return st_key[i];
		}
	}
}

void visitST_key(void(*visit)(Item))
{
	for (int i = 0; i < M; i++)
	{
		if (st_key[i] != NULLItem)
			visit(st_key[i]);
	}
}


//基于数组的有序符号表
static Item *st_array;
static int N_array;

void initST_array(int maxN)
{
	st_array = new Item[maxN + 1]();
	N_array = 0;
}

int countST_array()
{
	return N_array;
}

void insertST_array(Item item)	// 插入排序添加元素
{
	int j = N_array++;
	Key v = key(item);
	while (j > 0 && less(v, key(st_array[j - 1])))
	{
		st_array[j] = st_array[j - 1];
		j--;
	}
	st_array[j] = item;
}

Item searchST_array(Key v)	//顺序搜索
{
	for (int j = 0; j < N_array; j++)
	{
		if (eq(v, key(st_array[j])))
			return st_array[j];
		if (less(v, key(st_array[j])))
			break;
	}
	return NULLItem;
}

Item searchMiddle(int l, int r, Key v)
{
	int m = (l + r) / 2;
	if (l > r)
		return NULLItem;
	if (eq(v, key(st_array[m])))
		return st_array[m];
	if (l == r)
		return NULLItem;
	if less(v, key(st_array[m]))
		return searchMiddle(l, m - 1, v);
	else
		return searchMiddle(m + 1, r, v);
}
Item searchST_array_Mid(Key v)			//二分搜索
{
	return searchMiddle(0, N_array, v);
}

Item selectST_array(int k)
{
	return st_array[k];
}

void visitST_array(void(*visit)(Item))
{
	for (int i = 0; i < N_array; i++)
		visit(st_array[i]);
}


//基于链表的无序符号表
typedef struct STnode *link;
struct STnode{ Item item; link next; };
static link head, z;
static int N_list;

static link NEW(Item item, link next)
{
	link x = new struct STnode();
	x->item = item;
	x->next = next;
	return x;
}

void initST_list(int maxN)
{
	N_list = 0;
	head = (z = NEW(NULL, NULL));
}

int countST_list()
{
	return N_list;
}

Item search_list(link t, Key v)
{
	if (t == NULL)
		return NULLItem;
	if (eq(key(t->item), v))
		return t->item;
	return search_list(t->next, v);
}

Item searchST_list(link t, Key v)
{
	return search_list(head, v);
}

void insertST_list(Item item)
{
	head = NEW(item, head);
	N_list++;
}


