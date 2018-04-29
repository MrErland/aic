/*
function:Hash算法的效率比较
by:Erland
date:2017.7.24
*/

#include "Item.h"
#include "Methods.h"
#include <time.h>
#include <iostream>

void getrand(Item *a, int N)
{
	int i;
	for (i = 0; i < N; i++)
		a[i] = SIZE * (1.0*rand() / RAND_MAX);
}

int main()
{
	int a[NUM];
	getrand(a, NUM);
	double startT = clock();

//	linkedAddress(a);	//Time: 0.111S	链地址法	插入 100000 次, 查询 100000 次	While M is less than N,OK.
//	detection(a);		//Time: 0.019S	线性探测法	插入 100000 次, 查询 100000 次	While M is much more than N,better.
//	twoHash(a);		//Time: 0.028S	双重散列法	插入 100000 次, 查询 100000 次	While M is little more than N,better.
//	dynamicHash(a);		//Time: 0.033S	动态散列法	插入 100000 次, 查询 100000 次	M = 1000 at start.

	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S" << std::endl;
	return 0;
}

