/*
function:优先队列的实现
by:Erland
date:2017.7.7
*/

#pragma once
#include "sort.h"
#include "heap.h"
#include <stdlib.h>

/********************无序数组实现**********************/
static Item *pq1;
static int N1;

void initProque_1(int maxN)
{
	pq1 = new Item[maxN]();
	N1 = 0;
}

bool emptyProque_1()
{
	return N1 == 0;
}

void insertProque_1(Item v)
{
	pq1[N1++] = v;
}

Item deleProque_1()
{
	int j, max = 0;
	for (j = 1; j < N1; j++)
	{
		if (less(pq1[max], pq1[j]))
			max = j;
	}
	exch(pq1[max], pq1[N1 - 1]);
	return pq1[--N1];
}

/********************堆实现**********************/
static Item *pq2;
static int N2;

void initProque_2(int maxN)
{
	pq2 = new Item[maxN]();
	N2 = 0;
}

bool emptyProque_2()
{
	return N2 == 0;
}

void insertProque_2(Item v)		//从1开始到N2
{
	pq2[++N2] = v;
	fixup(pq2, N2);
}

Item deleProque_2()
{
	exch(pq2[1], pq2[N2]);
	fixdown(pq2, 1, N2 - 1);
	return pq2[N2--];
}

/********************无序双链表实现**********************/
typedef struct Prioq* Pq;
typedef struct PqNode* Pqlink;

struct PqNode{
	Item key;
	Pqlink prev, next;
};

struct Prioq{
	Pqlink head, tail;
};

Pq initProque_3()
{
	Pq pq = new Prioq();
	Pqlink h = new PqNode();
	Pqlink t = new PqNode();

	h->prev = t;
	h->next = t;
	t->prev = h;
	t->next = h;

	pq->head = h;
	pq->tail = t;
	return pq;
}

bool emptyProque_3(Pq pq)
{
	return pq->head->next->next == pq->head;
}

Pqlink insertProque_3(Pq pq, Item v)		//在头节点插入一个数
{
	Pqlink t = new PqNode();
	t->key = v;
	t->next = pq->head->next;
	t->next->prev = t;
	t->prev = pq->head;
	pq->head->next = t;
	return t;
}

Item deleProque_3(Pq pq)					//删除最大数
{
	Item max;
	Pqlink t, x = pq->head->next;
	for (t = x; t->next != pq->head; t = t->next)
	{
		if (t->key > x->key)
			x = t;
	}
	max = x->key;
	x->next->prev = x->prev;
	x->prev->next = x->next;
	delete x;
	return max;
}

void changeProque_3(Pq pq, Pqlink x, Item v)
{
	x->key = v;
}

void deleX_3(Pq pq, Pqlink x)
{
	x->next->prev = x->prev;
	x->prev->next = x->next;
	delete x;
}

void joinProque_3(Pq a, Pq b)				//合并两个链表
{
	a->tail->prev->next = b->head->next;
	b->head->next->prev = a->tail->prev;

	a->head->prev = b->tail;
	b->tail->next = a->head;

	delete a->tail;
	delete b->head;
}

/********************二项队列实现*********************/
typedef struct BQnode* BQlink;
typedef struct Bq* BQ;
#define z NULL
#define maxBQ 100
#define test(C, B, A) 4*(C)+2*(B)+(A)

struct BQnode{
	Item key;
	BQlink l, r;
};

struct Bq{
	BQlink *bq;
};

BQlink pair(BQlink p, BQlink q)
{
	if (less(p->key, q->key))
	{
		p->r = q->l;
		q->l = p;
		return q;
	}
	else{
		q->r = p->l;
		p->l = q;
		return p;
	}
}

BQlink insertBQ(BQ bq, Item v)
{
	int i;
	BQlink c, t = new struct BQnode();
	c = t;
	c->l = z;
	c->r = z;
	c->key = v;
	for (i = 0; i < maxBQ; i++)
	{
		if (c == z)
			break;
		if (bq->bq[i] == z)
		{
			bq->bq[i] = c;
			break;
		}
		c = pair(c, bq->bq[i]);
		bq->bq[i] = z;
	}
	return t;
}

void join(BQlink *a, BQlink *b)		//将b合并到a数组，没有考虑b内存释放问题
{
	int i;
	BQlink c = z;
	for (i = 0; i < maxBQ; i++)
	{
		switch (test(c != z, b[i] != z, a[i] != z))
		{
		case 2:
			a[i] = b[i];
			break;
		case 3:
			c = pair(a[i], b[i]);
			a[i] = z;
			break;
		case 4:
			a[i] = c;
			c = z;
			break;
		case 5:
			c = pair(c, a[i]);
			a[i] = z;
			break;
		case 6:
		case 7:
			c = pair(c, b[i]);
			break;
		}
	}
}

Item delemaxBQ(BQ bq)
{
	int i, max;
	BQlink x;
	Item v;
	BQlink temp[maxBQ];

	for (i = 0, max = -1; i < maxBQ; i++)
	{
		if (bq->bq[i] != z)
		{
			if (max == -1 || less(v, bq->bq[i]->key))
			{
				max = i;
				v = bq->bq[i]->key;
			}
		}
	}
	x = bq->bq[max]->l;
	for (i = max; i < maxBQ; i++)
		temp[i] = z;
	for (i = max; i > 0; i--)
	{
		temp[i - 1] = x;
		x = x->r;
		temp[i - 1]->r = z;
	}
	delete bq->bq[max];
	bq->bq[max] = z;
	join(bq->bq, temp);
	return v;
}

void joinBQ(BQ a, BQ b)
{
	join(a->bq, b->bq);
}
