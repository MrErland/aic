/*
function:Test
by:Erland
date:2017.7.25
*/

#define AdjMatrix
//#define AdjList
//#define LinkedListInStack

#include "Graph.h"
#include "AdjMatrix.h"
#include "AdjList.h"
#include "Path.h"
#include "Item.h"
#include <time.h>
#include <iostream>

int main()
{
	Graph G = graphRand(maxV, maxE);
	double startT = clock();



	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S." << std::endl;
	return 0;
}

