
#include "Item.h"
#ifdef LinkedListInStack
/*****************Stack Implementation By LInkedList***************/

typedef struct Stack* Pstack;
typedef struct StackNode* link;
struct Stack{ link head; int size; };
struct StackNode{ Item item; link next; };

link insertStack(Item item, link next)		//在next之前插入一个新的值为item的点
{
	link x = new StackNode;
	x->next = next;
	x->item = item;
	return x;
}

Pstack initStack()
{
	Pstack s = new Stack;
	s->head = NULL;
	s->size = 0;
	return s;
}

bool emptyStack(Pstack s)
{
	return s->head == NULL;
}

void pushStack(Pstack s, Item item)
{
	s->head = insertStack(item, s->head);
	s->size++;
}

Item popStack(Pstack s)
{
	if(emptyStack(s))
		return 0;
	Item item = s->head->item;
	link t = s->head->next;
	delete s->head;
	s->head = t;
	s->size--;
	return item;
}
#endif

#ifndef LinkedListInStack
/*****************Stack Implementation By Matrix***************/
typedef struct Stack{ Item* elem; int head; int cap; int size; }*Pstack;

Pstack initStack(int max)
{
	Pstack s = new Stack;
	s->elem = new Item[max]();
	s->cap = max;
	s->size = 0;
	s->head = 0;
	return s;
}

bool emptyStack(Pstack s)
{
	return s->head == 0;
}

void pushStack(Pstack s, Item item)
{
	if (s->head < s->cap)
	{
		s->elem[s->head] = item;
		s->head++;
		s->size++;
	}
}

Item popStack(Pstack s)
{
	if (emptyStack(s))
		return 0;
	Item t = s->elem[s->head - 1];
	s->head--;
	s->size--;
	return t;
}

#endif
