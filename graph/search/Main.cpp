/*
function:Test
by:Erland
date:2017.7.26
*/


//#define AdjMatrix
#define AdjList

#define QueueList
//#define QueueMatrix

#include "Graph.h"
#include "AdjMatrix.h"
#include "AdjList.h"
#include "Item.h"
#include "DFS.h"
#include "Queue.h"
#include "BFS.h"
#include "PFS.h"
#include <iostream>

void graphShortPath(Graph G, int s, int t)		//s->t最短路径
{
	int v;
	graphSerachPFS(G, t);						//RandSearch
//	graphSerachBFS(G, t);						//BFS
	for (v = s; v != t && v != -1; v = st[v])
		std::cout << v << "-";
	if (v == -1)
		std::cout << "No Path." << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	Graph G = graphRand(maxV, maxE);
	double startT = clock();

	graphShortPath(G, 97, 431);


	double endT = clock();
	std::cout << "Using Time: " << (endT - startT) / 1000 << " S." << std::endl;
	system("pause");
	return 0;
}

