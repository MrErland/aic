/*
function:平衡树_随机算法
by:Erland
date:2017.7.12
*/

#pragma once
#include <stdlib.h>
#include "Item.h"
#include "BST.h"

link_bst balanceB(link_bst h)	//平衡一颗二叉搜索树
{
	if (h->N < 2)
		return h;
	h = partB(h, h->N / 2);
	h->l = balanceB(h->l);
	h->r = balanceB(h->r);
	return h;
}

link_bst insertB_Rand(link_bst h, Item item)
{
	Key v = key(item), t = key(h->item);
	if (h == z_bst)
		return NEW(item, z_bst, z_bst, 1);
	if (rand() < RAND_MAX / (h->N + 1))		//根插入
		return insertR(h, item);
	if (less(v, t))						//标准插入
		h->l = insertB(h->l, item);
	else
		h->r = insertB(h->r, item);
	(h->N)++;
	return h;
}
void insertBST_Rand(Item item)	//随机插入BST
{
	head_bst = insertB_Rand(head_bst, item);
}


link_bst joinBST_Rand(link_bst, link_bst);
link_bst joinB_Rand(link_bst a, link_bst b)
{
	if (a == z_bst)
		return b;
	b = insertB(b, a->item);
	b->l = joinBST_Rand(a->l, b->l);
	b->r = joinBST_Rand(a->r, b->r);
	b->N = getCount(b);
	delete a;
	return b;
}
link_bst joinBST_Rand(link_bst a, link_bst b)	//随机组合BST
{
	if (rand() / (RAND_MAX / (a->N + b->N) + 1) < (a->N))
		return joinB_Rand(a, b);
	else
		return joinB_Rand(b, a);
}


link_bst joinLR_Rand(link_bst a, link_bst b)
{
	if (a == z_bst)
		return b;
	if (b == z_bst)
		return a;
	if (rand() / (RAND_MAX / (a->N + b->N) + 1) < (a->N))
	{
		a->r = joinLR_Rand(a->r, b);
		return a;
	}
	else{
		b->l = joinLR_Rand(a, b->l);
		return b;
	}
}
link_bst deleB_Rand(link_bst h, Key v)
{
	link_bst x;
	Key t = key(h->item);
	if (h == z_bst)
		return z_bst;
	if (less(v, t))
		h->l = deleB_Rand(h->l, v);
	if (less(t, v))
		h->r = deleB_Rand(h->r, v);
	if (equ(v, t))
	{
		x = h;
		h = joinLR_Rand(h->l, h->r);
		delete x;
	}
	h->N = getCount(h);
	return h;
}
void deleBST_Rand(Key v)
{
	head_bst = deleB_Rand(head_bst, v);
}
