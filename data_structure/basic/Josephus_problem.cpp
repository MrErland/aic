/*
function:约瑟夫问题(循环链表模拟法)
by:Erland
data:2017.6.22
*/

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(int argc, char *argv[])
{
//	testRerverse(randomList(30, 20));
//	link b = sortInsert(randomList(30, 20));

	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	link t = new node();
	link x;

	//初始化循环链表
	t->item = 1;
	t->nextNode = t;
	x = t;

	for (int i = 2; i <= N; i++)
	{
		insertNode(t, i);
		t = t->nextNode;
	}
	
	while (x != x->nextNode)		//至少还有一个人
	{
		for (int i = 1; i < M - 1; i++)	//找到要删除的节点的位置
			x = x->nextNode;

		cout << x->nextNode->item << " ";
		deleteNode(x);
		x = x->nextNode;
		N--;
	}
	cout << endl;
	cout << "Last Person: " << x->item << endl;

	return 0;
}
