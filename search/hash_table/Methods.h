/*
function:Test
by:Erland
date:2017.7.24
*/

#pragma once
#include "Detection.h"
#include "Item.h"
#include "ST.h"
#include "DynamicHash.h"

void linkedAddress(int a[])
{
	initST(NUM);
	for (int i = 0; i < NUM; i++)
		insertST(a[i]);
	for (int j = NUM - 1; j >= 0; j--)
		searchST(a[j]);
}

void detection(int a[])
{
	init_Det(NUM);
	for (int i = 0; i < NUM; i++)
		insert_Det(a[i]);
	for (int j = NUM - 1; j >= 0; j--)
		search_Det(a[j]);
}

void twoHash(int a[])
{
	init_Det(NUM);
	for (int i = 0; i < NUM; i++)
		insert_Two(a[i]);
	for (int j = NUM - 1; j >= 0; j--)
		search_Two(a[j]);
}

void dynamicHash(int a[])
{
	init_Det(maxKey);
	for (int i = 0; i < NUM; i++)
		insert_Dynamic(a[i]);
	for (int j = NUM - 1; j >= 0; j--)
		search_Det(a[j]);
}

