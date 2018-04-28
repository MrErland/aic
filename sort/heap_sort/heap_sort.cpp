#include <time.h>
#include "heap_sort.h"
#include "quick_sort.h"
#include <iostream>

int main()
{
	int a[NUM];	
	getrand(a, NUM);
	double startT = clock();

//	quickSort_1(a, 0, NUM - 1);		//标准快速		0.051S

//	prioqueSort(a, 0, NUM - 1);		//优先队列排序		0.098S
//	heapSort(a, 0, NUM - 1);		//标准堆排序		0.081S

	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S" << std::endl;
	return 0;
}

