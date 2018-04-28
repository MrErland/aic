/*
**********************************Tree Implementation***************
*/

#include <iostream>
#include <queue>
#include "Tree.h"
#include "Stack_List.h"
#include "FIFO_List.h"

void visit(node h)		//访问h节点，并输出
{
	std::cout << h->item;
	std::cout << " ";
}

void visit(Item item)
{
	std::cout << item;
	std::cout << " ";
}

void traversePre(node h)
{
	if (h == NULL) return;
	visit(h);
	traversePre(h->l);
	traversePre(h->r);
}

void traverseIn(node h)
{
	if (h == NULL) return;
	traverseIn(h->l);
	visit(h);
	traverseIn(h->r);
}

void traversePost(node h)
{
	if (h == NULL) return;
	traversePost(h->l);
	traversePost(h->r);
	visit(h);
}

//栈实现前序遍历
void traverse(node h)
{
	Pstack s = initStack();
	PushStack(s, h->item);
	while (!Empty(s))
	{
		Item t = PopStack(s);
		visit(t);
		if (h->r != NULL)
			PushStack(s, h->r->item);
		if (h->l != NULL)
			PushStack(s, h->l->item);
	}
}

//队列实现层序遍历
void traverseFloor(node h)
{
	Q que = InitQueue();
	PutQueue(que, h->item);
	while (!EmptyQueue(que))
	{
		visit(PopQueue(que));
		if (h->l != NULL)
			PutQueue(que, h->l->item);
		if (h->r != NULL)
			PutQueue(que, h->r->item);
	}
}

int count(node root)
{
	if (root == NULL)
		return 0;
	return count(root->l) + count(root->r) + 1;
}

int getDepth(node root)
{
	if (root == NULL)
		return -1;
	int left = getDepth(root->l);
	int right = getDepth(root->r);
	return left > right ? left + 1 : right + 1;
}

int getWidth(node root)
{
	if (root == NULL)
		return 0;
	int lastWidth = 1;	//上一层
	int curWidth = 0;
	int treeWidth = 1;
	node top = NULL;
	std::queue <node> floor;
	floor.push(root);

	while (!floor.empty())
	{
		curWidth = lastWidth;
		while (curWidth != 0)
		{
			top = floor.front();//取出队列头元素  
			floor.pop();//将队列头元素出队

			if (top->l != NULL)
				floor.push(top->l);
			if (top->r != NULL)
				floor.push(top->r);

			curWidth--;
		}
		curWidth = floor.size();
		if (curWidth > lastWidth)
			treeWidth = curWidth;
		lastWidth = curWidth;
	}
	return treeWidth;
}

node initTree(int n)
{
	int i, a, b;
	int num = 1;
	node nodeTree = new tree[n + 1]();	//建立n个节点的二叉树
	nodeTree[1].item = 1;				//根节点
	for (i = 1; i <= n; i++)
	{
		std::cin >> a >> b;				//输入第i个节点的左右儿子
		if (a != 0)
		{
			num++;
			nodeTree[num].item = a;
			nodeTree[i].l = &nodeTree[num];
		}
		else
			nodeTree[i].l = NULL;
		if (b != 0)
		{
			num++;
			nodeTree[num].item = b;
			nodeTree[i].r = &nodeTree[num];
		}
		else
			nodeTree[i].r = NULL;
	}
	return &nodeTree[1];				//返回树根
}


//联赛构造
node Newnode(Item item, node l, node r)
{
	node x = new tree();
	x->item = item;
	x->l = l;
	x->r = r;
	return x;
}
node max(Item a[], int l, int r)
{
	int m = (l + r) / 2;
	Item u, v;
	node x = Newnode(a[m], NULL, NULL);
	if (l == r)
		return x;
	x->l = max(a, l, m);
	x->r = max(a, m + 1, r);
	u = x->l->item;
	v = x->r->item;
	x->item = (u > v ? u : v);
	return x;
}
