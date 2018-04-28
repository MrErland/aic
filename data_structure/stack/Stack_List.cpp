/******************Stack Implementation By LInkedList***************/

#include <iostream>
#include "StackImple.h"

link Insert(Item item, link next)
{
	link x = new StackNode();
	x->next = next;
	x->item = item;
	return x;
}

Pstack initStack()
{
	Pstack s = new Stack();
	s->head = NULL;
	s->size = 0;
	return s;
}

bool Empty(Pstack s)
{
	return s->head == NULL;
}

void PushStack(Pstack s, Item item)
{
	s->head = Insert(item, s->head);
	s->size++;
}

Item PopStack(Pstack s)
{
	if (Empty(s)) return NULL;
	Item item = s->head->item;
	link t = s->head->next;
	delete s->head;
	s->head = t;
	s->size--;
	return item;
}
