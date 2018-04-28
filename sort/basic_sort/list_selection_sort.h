#ifndef _list_selection_sort_
#define _list_selection_sort_

#include <stdlib.h>
typedef int Item;
typedef struct list* link;
struct list{ Item item; link next; };

link findMax(link h)			//寻找最大值点的前一个节点
{
	link max;
	Item M = h->item;
	while (h->next != NULL)
	{
		if (h->next->item > M)
		{
			max = h;
			M = h->next->item;
		}
		h = h->next;
	}
	return max;
}

link listSelection(link h)		//链表选择排序
{
	link max, t, out = NULL;
	while (h->next != NULL)
	{
		max = findMax(h);
		t = max->next;
		max->next = t->next;
		t->next = out;
		out = t;
	}
	h->next = out;
	return h;
}

#endif
