/*
function:二叉搜索树
by:Erland
date:2017.7.11
*/

#pragma once
#include "Item.h"

link_bst NEW(Item item, link_bst  l, link_bst r, int N)
{
	link_bst x = new struct BSTnode();
	x->item = item;
	x->l = l;
	x->r = r;
	x->N = N;
	return x;
}

void initBST()		//建二叉树
{
	head_bst = (z_bst = NEW(NULLItem, 0, 0, 0));
}

int countBST()		//结点计数
{
	return head_bst->N;
}

Item searchB(link_bst h, Key v)
{
	Key t = key(h->item);
	if (h == z_bst)
		return NULLItem;
	if (equ(v, t))
		return h->item;
	if less(v, t)
		return searchB(h->l, v);
	else
		return searchB(h->r, v);
}
Item searchBST(Key v)		//二叉搜索
{
	return searchB(head_bst, v);
}


link_bst insertB(link_bst h, Item item)
{
	Key v = key(item), t = key(h->item);
	if (h == z_bst)
		return NEW(item, z_bst, z_bst, 1);
	if less(v, t)
		h->l = insertB(h->l, item);
	else
		h->r = insertB(h->r, item);
	(h->N)++;
	return h;
}
void insertBST(Item item)	//插入元素
{
	head_bst = insertB(head_bst, item);
}


void visitB(link_bst h, void(*visit)(Item))		
{
	if (h == z_bst)
		return;
	visitB(h->l, visit);
	visit(h->item);
	visitB(h->r, visit);
}
void visitBST(void(*visit)(Item))		//中序遍历访问
{
	visitB(head_bst, visit);
}


// 带旋转的操作的二叉树

int getCount(link_bst h)		//节点计数域更新函数
{
	if (h == z_bst) return 0;
	int n = 0;
	if (h->l != z_bst)
	{
		++n;
		n += getCount(h->l);
	}
	else return 0;
	if (h->r != z_bst)
	{
		++n;
		n += getCount(h->r);
	}	
	else return 0;
	return n;
}

link_bst rotR(link_bst h)	//旋转操作 S -> E
{
	link_bst x = h->l;
	h->l = x->r;
	x->r = h;
	x->N = getCount(x);
	h->N = getCount(h);
	return x;
}

link_bst rotL(link_bst h)	//旋转操作 A -> E
{
	link_bst x = h->r;
	h->r = x->l;
	x->l = h;
	x->N = getCount(x);
	h->N = getCount(h);
	return x;
}


link_bst insertR(link_bst h, Item item)
{
	Key v = key(item);
	if (h == z_bst) return NEW(item, z_bst, z_bst, 1);
	if (less(v, key(h->item)))
	{
		h->l = insertR(h->l, item);
		h = rotR(h);
	}
	else{
		h->r = insertR(h->r, item);
		h = rotL(h);
	}
	return h;
}
void insertR_BST(Item item)		//带自旋的根插入
{
	head_bst = insertR(head_bst, item);
}


Item selectK(link_bst h, int k)		
{
	int t;
	if (h == z_bst)
		return NULLItem;
	t = (h->l == z_bst) ? 0 : h->l->N;
	if (t > k)
		return selectK(h->l, k);
	if (t < k)
		return selectK(h->r, k - t - 1);
	return h->item;
}
Item selectKeyBST(int k)		//找到第K小的关键字数据
{
	return selectK(head_bst, k);
}


link_bst partB(link_bst h, int k)	//划分操作,把第K小的关键字数据移到树根
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
link_bst joinLR(link_bst a, link_bst b)
{
	if (b == z_bst)
		return a;
	b = partB(b, 0);
	b->l = a;
	b->N = getCount(b);
	return b;
}
link_bst deleK(link_bst h, Key v)
{
	link_bst x;
	Key t = key(h->item);
	if (h == z_bst)
		return z_bst;
	if (less(v, t))
		h->l = deleK(h->l, v);
	if (less(t, v))
		h->r = deleK(h->r, v);
	if (equ(v, t))
	{
		x = h;
		h = joinLR(h->l, h->r);
		delete x;
	}
	h->N = getCount(h);
	return h;
}
void deleteKeyBST(Key v)		//删除一个给定的关键字数据
{
	head_bst = deleK(head_bst, v);
}


link_bst joinBST(link_bst a, link_bst b)	//连接a,b两个树,得到b
{
	if (b == z_bst) return a;
	if (a == z_bst) return b;
	b = insertR(b, a->item);
	b->l = joinBST(a->l, b->l);
	b->r = joinBST(a->r, b->r);
	b->N = getCount(b);
	delete a;
	return b;
}
