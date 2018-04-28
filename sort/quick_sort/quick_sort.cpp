/*
function:几种排序方法的效率比较
by:Erland
date:2017.7.4
conclusion:
		数据量:200000
		希尔排序快插入排序28.7倍
		快速排序快希尔排序20.4倍
*/

#include "shell_sort.h"
#include "quick_sort.h"
#include "sort.h"
#include "select.h"
#include <time.h>
#include <iostream>

#define NUM 200000

int main()
{
	int a[NUM];	
	getrand(a, NUM);
	double startT = clock();

//	insertion(a, 0, NUM - 1);	//插入排序	23.185S
//	shellsortt(a, 0, NUM - 1);	//希尔排序	0.806S
//	quickSort_1(a, 0, NUM - 1);	//标准快速	0.042S
//	quickSort_2(a, 0, NUM - 1);	//非递归快速	1.338S	
//	advanced_1(a, 0, NUM - 1);	//三者取中的快速	0.032S
//	advanced_2(a, 0, NUM - 1);	//三路划分的快速	0.019S	含有大量重复数值时,效率会更高

	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S" << std::endl;

	int k = 5;		
	int l = 1;
	int b[8] = { 5, 9, 2, 4, 3, 6, 1, 7 };
	select2(b, l, 7, k);
	std::cout << b[k + l - 1] << std::endl;		//K+l-1

	return 0;
}

