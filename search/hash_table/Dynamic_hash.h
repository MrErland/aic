/*
function:动态散列表
by:Erland
date:2017.7.24
*/

#pragma once
#include "Item.h"
#include "Detection.h"

void expend_hash()
{
	int i;
	Item  *t = st;
	init_Det(2 * M_D);
	for (i = 0; i < M_D / 2; i++)
	{
		if (key(t[i]) != NULLItem)
			insert_Det(t[i]);
	}
	delete[] t;
}

void insert_Dynamic(Item item)
{
	Key v = key(item);
	int i = hash(v, M_D);
	while (key(st[i]) != NULLItem)
		i = (i + 1) % M_D;
	st[i] = item;
	if (N_D++ >= M_D / 2)
		expend_hash();
}

