/*
function:搜索算法
by:Erland
date:2017.7.10
*/

#include "Methods.h"
#include <time.h>
#include <iostream>

void getrand(Item *a, int N)
{
	for (int i = 0; i < N; i++)
		a[i] = SIZE * (1.0*rand() / RAND_MAX);
}

int main()
{
	int a[NUM];
	getrand(a, NUM);
	double startT = clock();
					
//	basicBST(a);			//	标准BST	32.475S		插入 50000 ,删除 5000 个	可能存在最差性能
//	randBST(a);				//	随机BST	28.397S		插入 50000 ,删除 5000 个	较优
//	splayBST(a);			//  伸展BST	282.576S	插入 50000 ,删除 5000 个	较慢
//	rootBST(a);				//  根插入	241.871S	插入 50000 ,删除 5000 个	较慢
//	redblackBST(a);			//	红黑BST	104.439S	插入 50000 ,删除	5000 个	插入效率不够优
//	skiplist(a);			//	跳跃表	2.503S		插入 50000 ,删除	5000 个	空间占据较大

	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S" << std::endl;
	return 0;
}

