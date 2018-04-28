/*
by:Erland
date:2017.6.21
*/

#include <iostream>

#ifndef _singal_list_
#define _singal_list_

#define Item int
#define NUM_TEST 20

typedef struct node *link;
struct node {Item item; link  nextNode;};

void insertNode(link s, Item t)	//s节点后插入值为t的节点
{
	link inse = new node();
	inse->nextNode = s->nextNode;
	s->nextNode = inse;
	inse->item = t;
}

void deleteNode(link s)	//删除s节点后的t节点
{
	link t = s->nextNode;
	s->nextNode = t->nextNode;
	delete t;
}

link visitList(link s, Item t)	//从s节点开始，遍历查找值t的节点
{
	link temp;
	for (temp = s; temp != NULL; temp = temp->nextNode)
	{
		if (temp->item == t) return temp;
	}
	return nullptr;
}

link reverseList(link s)	//输出链表逆序
{
	link t, x = s->nextNode, r = NULL;
	delete s;
	while (x != NULL)
	{
		t = x->nextNode;
		x->nextNode = r;
		r = x;
		x = t;
	}
	t = new node(); t->nextNode = r;	//新的哑结点
	return t;
}

void printList(link s)		//从S节点输出单向链表
{
	for (link t = s->nextNode; t != NULL; t = t->nextNode)
	{
		std::cout << t->item << " ";
	}
	std::cout << std::endl;
}

link sortInsert(link a)	//链表插入排序，返回排序后的头节点
{
	link t, u, v, b;	
	b = new node();		//头节点为哑元节点，不保存实际数据
	b->nextNode = NULL;
	for (t = a->nextNode; t != NULL; t = u)
	{
		u = t->nextNode;
		for (v = b; v->nextNode != NULL; v = v->nextNode)
		{
			if (v->nextNode->item > t->item)
				break;
		}
		t->nextNode = v->nextNode;
		v->nextNode = t;
	}
	//测试排序后链表
	printList(b);
	return b;
}

void testRerverse(link a)		//翻转链表测试
{
	link s = reverseList(a);
	printList(s);
}

link randomList(int length, int n)		// 产生随机链表，长度length，数值范围在n
{
	link a = new node();
	link t = a;
	for (int i = 0; i < length; i++)
	{
		t->nextNode = new node();
		t = t->nextNode;
		t->nextNode = NULL;
		t->item = rand() % n;
	}
	//测试随机链表
	printList(a);
	return a;
}

#endif
