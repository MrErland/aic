/*
function:Test
by:Erland
date:2017.8.18
*/

//#define AdjMatrix
#define AdjList

#include "Graph.h"
#include "AdjMatrix.h"
#include "AdjList.h"
#include "Item.h"
#include "FordFulkerson.h"
#include "PreFlowPush.h"
#include "FeasibleFlow.h"
#include "DInic.h"
#include <iostream>


int main()
{
	Graph G = graphRand(maxV, maxE);
	double startT = clock();

	int s = 0;				//起点
	int t = maxV - 1;

//	graphShow(G);
//	GraphMaxFlow(G, s, t);
//	GraphMaxFlow_PP(G, s, t);
//	flowShow(G);

//	int st = GraphFeasible(G);				//可行流测试
//	std::cout << st << std::endl;

	double endT = clock();
	std::cout << std::endl << "Using Time: " << (endT - startT) / 1000 << " S." << std::endl;
	system("pause");
	return 0;
}

