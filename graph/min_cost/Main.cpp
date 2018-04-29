/*
function:Test
by:Erland
date:2017.8.28
*/

//#define AdjMatrix
#define AdjList

#include "Graph.h"
#include "AdjMatrix.h"
#include "AdjList.h"
#include "Item.h"
#include "CycleCanceling.h"
#include "NetworkSimplex.h"
#include <iostream>


int main()
{
//	Graph G = graphRand(maxV, maxE);
	Graph G = graphReadFile();
	double startT = clock();

	int s = 0;				//起点
	int t = V - 1;
	int cost;
	graphShow(G);

	cost = graphMinCost(G, s, t);
//	cost = GraphMinCost(G, s, t);

	std::cout << "\nMinCost: " << cost << std::endl;

	double endT = clock();
	std::cout << std::endl << "Using Time: " << (endT - startT) / 1000 << " S." << std::endl;
	return 0;
}

