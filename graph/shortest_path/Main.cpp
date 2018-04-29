/*
function:Test
by:Erland
date:2017.8.11
*/

//#define AdjMatrix
#define AdjList

#include "Graph.h"
#include "AdjMatrix.h"
#include "AdjList.h"
#include "Item.h"
#include "Dijkstra.h"
#include "SPAll.h"
#include "DAG.h"
#include "Bellman-Ford.h"
#include <iostream>

int main()
{
	Graph G = graphRand(maxV, maxE);
	double startT = clock();


	int st[maxV];			//父结点
	double wt[maxV + 1];	//最短路径长度
	int s = 0;				//起点

//单源点Dijstra测试
//	graphShow(G);
//	GraphSPTDij(G, st, wt, s);


//所有源点最短路测试
//	GraphSPAllF(G);			//0.970S
//	GraphSPAllD(G);			//0.362S


//Bellman-Ford测试
	GraphBF(G, st, wt, s);

	for (int i = 1; i <= maxV; i++)
	{
		std::cout << std::setw(4) << wt[i - 1] << " ";
		if (i % 20 == 0)
			std::cout << std::endl;
	}

	double endT = clock();
	std::cout << std::endl << "Using Time: " << (endT - startT) / 1000 << " S." << std::endl;
	return 0;
}

