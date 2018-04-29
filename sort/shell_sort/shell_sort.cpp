/*
function:比较希尔排序和插入排序效率
by:Erland
date:2017.7.4
conclusion:数据量:200000,希尔排序快28.7倍
*/

#include "shell_sort.h"
#include "sort.h"
#include <ctime>
#include <iostream>

#define NUM 200000

int main()
{
	int a[NUM];	
	getrand(a, NUM);
	double startT = clock();

//	insertion(a, 0, NUM - 1);
	shellsort(a, 0, NUM - 1);

	double endT = clock();
	std::cout << "Using Time: " << (endT - startT)/1000 << "s." << std::endl;
	return 0;
}

