/*
function:算法测试
by:Erland
date:2017.7.13
*/

#pragma once
#include "BST.h"
#include "Item.h"
#include "BST_Random.h"
#include "BST_Splay.h"
#include "BST_RedBlack.h"
#include "SkipList.h"

#define NUM_DELETE 5000

void basicBST(int a[])			//标准插入，标准删除
{
	int i;
	initBST();
	for (i = 0; i < NUM; i++)
	{
		insertBST(a[i]);
	}
	for (i = NUM / 2; i < NUM / 2 + NUM_DELETE; i++)
	{
		deleteKeyBST(a[i]);
	}
}

void randBST(int a[])			//随机插入，随机删除
{
	int i;
	initBST();
	for (i = 0; i < NUM; i++)
	{
		insertBST_Rand(a[i]);
	}
	for (i = NUM / 2; i < NUM / 2 + NUM_DELETE; i++)
	{
		deleBST_Rand(a[i]);
	}
}

void splayBST(int a[])			//伸展插入，标准删除
{
	int i;
	initBST();
	for (i = 0; i < NUM; i++)
	{
		insertBST_SP(a[i]);
	}
	for (i = NUM / 2; i < NUM / 2 + NUM_DELETE; i++)
	{
		deleteKeyBST(a[i]);
	}
}

void rootBST(int a[])			//根插入，标准删除
{
	int i;
	initBST();
	for (i = 0; i < NUM; i++)
	{
		insertR_BST(a[i]);
	}
	for (i = NUM / 2; i < NUM / 2 + NUM_DELETE; i++)
	{
		deleteKeyBST(a[i]);
	}
}

void redblackBST(int a[])			//红黑插入，标准删除
{
	int i;
	init_RB();
	for (i = 0; i < NUM; i++)
	{
		insertBST_RB(a[i]);
	}
	for (i = NUM / 2; i < NUM / 2 + NUM_DELETE; i++)
	{
		delete_RB(a[i]);
	}
}

void skiplist(int a[])				//跳跃表插入，删除
{
	int i;
	init_SK();
	for (i = 0; i < NUM; i++)
	{
		insert_SK(a[i]);
	}
	for (i = NUM / 2; i < NUM / 2 + NUM_DELETE; i++)
	{
		delete_SK(a[i]);
	}
}
