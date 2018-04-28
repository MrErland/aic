/***************Queue by List****************/
#ifndef _queue_by_list_
#define _queue_by_list_

#define Item int

typedef struct QueueNode* link;
typedef struct Queue* Q;

struct Queue{ link head; link tail; };
struct QueueNode { Item item; link next; };

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

inline link New(Item item, link next)	//在next前插入一个数
{
	link x = new QueueNode();
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
		return -1;
	Item item = q->head->item;
	link t = q->head->next;
	delete q->head;
	q->head = t;
	return item;
}

#endif
