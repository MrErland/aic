/*
function:平衡树_伸展算法
by:Erland
date:2017.7.12
*/

#pragma once
#include "Item.h"
#include "BST.h"

link_bst splay(link_bst h, Item item)
{
	Key v = key(item);
	if (h == z_bst)
		return NEW(item, z_bst, z_bst, 1);
	if less(v, key(h->item))
	{
		if (h->l == z_bst)
			return NEW(item, z_bst, h, h->N + 1);
		if (less(v, key(h->l->item)))
		{
			h->l->l = splay(h->l->l, item);
			h = rotR(h);
		}
		else{
			h->l->r = splay(h->l->r, item);
			h->l = rotL(h->l);
		}
		return rotR(h);
	}
	else{
		if (h->r == z_bst)
			return NEW(item, h, z_bst, h->N + 1);
		if (less(key(h->r->item), v))
		{
			h->r->r = splay(h->r->r, item);
			h = rotL(h);
		}
		else{
			h->r->l = splay(h->r->l, item);
			h->r = rotR(h->r);
		}
		return rotL(h);
	}
}
void insertBST_SP(Item item)
{
	head_bst = splay(head_bst, item);
}
