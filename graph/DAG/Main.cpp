/*
function:Test
by:Erland
date:2017.8.1
*/

#define AdjMatrix
//#define AdjList

#include "Graph.h"
#include "AdjMatrix.h"
#include "AdjList.h"
#include "Item.h"
#include "DFS.h"
#include "TC.h"
#include "TS.h"
#include "DagTC.h"
#include <iostream>

int main()
{
	Graph G = graphRand(maxV, maxE);
	double startT = clock();




	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S." << std::endl;
	return 0;
}

