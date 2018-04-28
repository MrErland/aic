#include "sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include <time.h>
#include <iostream>

#define NUM 25000

int main()
{
	int a[NUM];	
	getrand(a, NUM);
	double startT = clock();

//	quickSort_1(a, 0, NUM - 1);		//标准快速	0.051S			

//	mergeSort(a, 0, NUM - 1);		//自顶向下归并	0.078S
//	mergeSortAB(a, 0, NUM - 1);		//没有复制归并	0.003S
//	mergeSortBU(a, 0, NUM - 1);		//自底向上归并	0.079S	
	
	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S" << std::endl;
	return 0;
}
