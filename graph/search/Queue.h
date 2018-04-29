/*
function:Queue Implement
by:Erland
date:2017.7.26
*/

#pragma once
#include "Item.h"
#define Item Edge

//基于链表
#ifdef QueueList

typedef struct QueueNode* qlink;
typedef struct Queue* Q;	//可定义多个队列
struct Queue{ qlink head; qlink tail; };
struct QueueNode { Item item; qlink next; };

Q InitQueue()
{
	Q q = new Queue();
	q->head = NULL;
	q->tail = NULL;
	return q;
}

bool EmptyQueue(Q q)
{
	return q->head == NULL;
}

qlink New(Item item, qlink next)	//在next前插入一个数
{
	qlink x = new QueueNode();
	x->item = item;
	x->next = next;
	return x;
}

void PutQueue(Q q, Item item)		//队列中加入一个元素
{
	if (q->head == NULL)
	{
		q->tail = New(item, q->head);
		q->head = q->tail;
		return;
	}
	q->tail->next = New(item, q->tail->next);
	q->tail = q->tail->next;
}

Item GetQueue(Q q)
{
	if (q->head == NULL)
		return{};							//注意这个返回值
	Item item = q->head->item;
	qlink t = q->head->next;
	delete q->head;
	q->head = t;
	return item;
}

#endif 

//基于数组
#ifdef QueueMatrix
static Item *q;
static int N, headArray, tailArray;

void InitQue(int Max)	//设置同时存在的最多数目Max
{
	N = Max + 1;
	q = new Item[N]();
	headArray = N;		//head从N开始，回卷后重合
	tailArray = 0;		//tail从0开始
}

bool EmptyQue()
{
	return headArray%N == tailArray;
}

void PutQue(Item item)
{
	q[tailArray++] = item;
	tailArray = tailArray%N;
}

Item GetQue()
{
	headArray = headArray%N;
	return q[headArray++];
}

#endif
