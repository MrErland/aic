/*
function:平衡树_红黑树_2-3-4树
by:Erland
date:2017.7.20
*/

#pragma once
#include "Item.h"
#include "BST.h"

//重写部分函数
link_rb NEW(Item item, link_rb  l, link_rb r, int N, bool b)
{
	link_rb x = new struct RBnode();
	x->item = item;
	x->l = l;
	x->r = r;
	x->N = N;
	x->red = b;
	return x;
}
void init_RB()
{
	head_rb = (z_rb = NEW(NULLItem, 0, 0, 0, 0));
}
void fixN(link_rb h, int *n)
{
	if (h->l != z_rb)
	{
		(*n)++;
		fixN(h->l, n);
	}
	if (h->r != z_rb)
	{
		(*n)++;
		fixN(h->r, n);
	}
	return;
}
int getCount(link_rb h)
{
	int n = 0;
	if (h == z_rb)
		return 0;
	else
	{
		fixN(h, &n);
		return n + 1;
	}
}
link_rb rotR(link_rb h)	//S -> E
{
	link_rb x = h->l;
	h->l = x->r;
	x->r = h;
	x->N = getCount(x);
	h->N = getCount(h);
	return x;
}

link_rb rotL(link_rb h)	//A -> E
{
	link_rb x = h->r;
	h->r = x->l;
	x->l = h;
	x->N = getCount(x);
	h->N = getCount(h);
	return x;
}


link_rb insertB_RB(link_rb h, Item item, bool sw)
{
	Key v = key(item);
	if (h == z_rb)
		return NEW(item, z_rb, z_rb, 1, 1);
	if ((h->l->red) && (h->r->red))
	{
		h->red = 1;
		h->l->red = 0;
		h->r->red = 0;
	}
	if (less(v, key(h->item)))
	{
		h->l = insertB_RB(h->l, item, 0);
		if (h->red && h->l->red && sw)
			h = rotR(h);
		if (h->l->red && h->l->l->red)
		{
			h = rotR(h);
			h->red = 0;
			h->r->red = 1;
		}
	}
	else{
		h->r = insertB_RB(h->r, item, 1);
		if (h->red && h->r->red && !sw)
			h = rotL(h);
		if (h->r->red && h->r->r->red)
		{
			h = rotL(h);
			h->red = 0;
			h->l->red = 1;
		}
	}
	h->N = getCount(h);
	return h;
}
void insertBST_RB(Item item)		//红黑树插入，维持2-3-4树
{
	head_rb = insertB_RB(head_rb, item, 0);
}


link_rb partB(link_rb h, int k)
{
	int t = h->l->N;
	if (t > k)
	{
		h->l = partB(h->l, k);
		h = rotR(h);
	}
	if (t < k)
	{
		h->r = partB(h->r, k - t - 1);
		h = rotL(h);
	}
	return h;
}
link_rb joinLR(link_rb a, link_rb b)
{
	if (b == z_rb)
		return a;
	b = partB(b, 0);
	b->l = a;
	b->N = getCount(b);
	return b;
}
link_rb deleB(link_rb h, Key v)
{
	link_rb x;
	Key t = key(h->item);
	if (h == z_rb)
		return z_rb;
	if (less(v, t))
		h->l = deleB(h->l, v);
	if (less(t, v))
		h->r = deleB(h->r, v);
	if (equ(v, t))
	{
		x = h;
		h = joinLR(h->l, h->r);
		delete x;
	}
	h->N = getCount(h);
	return h;
}
void delete_RB(Key v)		//重写标准删除
{
	head_rb = deleB(head_rb, v);
}

