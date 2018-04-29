/***************Queue****************/

#pragma once
#include <iostream>
#define Item int

static Item *q;
static int QueSize, headArray, tailArray;

void InitQue(int Max)	//设置同时存在的最多数目Max
{
	QueSize = Max + 1;
	q = new Item[QueSize]();
	headArray = QueSize;		//head从QueSize开始，回卷后重合
	tailArray = 0;		//tail从0开始
}

bool EmptyQue()
{
	return headArray%QueSize == tailArray;
}

void PutQue(Item item)
{
	q[tailArray++] = item;
	tailArray = tailArray%QueSize;
}

Item GetQue()
{
	headArray = headArray%QueSize;
	return q[headArray++];
}


