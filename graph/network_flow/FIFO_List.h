/*FIFO*/

#pragma once
typedef struct QueueNode* point;
typedef struct Queue* Que;
#define Item int

struct Queue{ point head; point tail; };
struct QueueNode { Item item; point next; };

Que InitQueue()
{
	Que q = new Queue();
	q->head = NULL;
	q->tail = NULL;
	return q;
}

bool EmptyQueue(Que q)
{
	return q->head == NULL;
}

point New(Item item, point next)
{
	point x = new QueueNode();
	x->item = item;
	x->next = next;
	return x;
}

void PutQueue(Que q, Item item)
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

Item GetQueue(Que q)
{
	if (q->head == NULL)
		return -1;
	Item item = q->head->item;
	point t = q->head->next;
	delete q->head;
	q->head = t;
	return item;
}


