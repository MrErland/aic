#include "Item.h"
#include "BST.h"
#include "ST.h"
#include <time.h>
#include <iostream>

void getrand(Item *a, int N)
{
	for (int i = 0; i < N; i++)
		a[i] = SIZE * (1.0 * rand() / RAND_MAX);
}

int main()
{
	int a[NUM];
	getrand(a, NUM);
	double startT = clock();



	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S" << std::endl;
	return 0;
}

