/*
function:无重复项的FIFO队列
by:Erland
date:2017.8.23
*/

#define Item int

static Item *q;
static bool *book;
static int size, headArray, tailArray;

void InitQue(int Max)	//设置同时存在的最多数目Max
{
	size = Max + 1;
	q = new Item[size];
	book = new bool[size];
	for (int i = 0; i < size; i++)
		book[i] = 0;
	headArray = size;		//head从size开始，回卷后重合
	tailArray = 0;		//tail从0开始
}

bool EmptyQue()
{
	return headArray%size == tailArray;
}

void PutQue(Item item)
{
	if (book[item] == 1)
		return;
	q[tailArray++] = item;
	tailArray = tailArray%size;
	book[item] = 1;
}

Item GetQue()
{
	headArray = headArray%size;
	book[q[headArray]] = 0;
	return q[headArray++];
}


