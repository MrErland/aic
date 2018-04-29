/*
function:有向图DFS实现
by:Erland
date:2017.8.3
*/

#ifdef AdjList
#include "AdjList.h"
#include <string>
#include <iostream>

static int cntP = 0;
static int post[maxV];

void show(std::string s, Edge e)
{
	std::cout << e.v << "-" << e.w << " " << s << std::endl;
}
void DFS(Graph G, Edge e)
{
	link t;
	int i, v, w = e.w;
	Edge x;
	show("tree", e);
	pre[w] = cnt++;
	for (t = G->adj[w]; t != NULL; t = t->next)
	{
		if (pre[t->v] == -1)
			DFS(G, EDGE(w, t->v));
		else
		{
			v = t->v;
			x = EDGE(w, v);
			if (post[v] == -1)
				show("back", x);
			else if (pre[v] > pre[w])
				show("down", x);
			else
				show("cross", x);
		}
	}
	post[w] = cntP++;
}

void grapgSearchDFS(Graph G)
{
	int v;
	cnt = 0;
	cntP = 0;
	for (v = 0; v < G->V; v++)
		pre[v] = post[v] = -1;
	for (v = 0; v < G->V; v++)
	{
		if (pre[v] == -1)
			DFS(G, EDGE(v, v));
	}
}

#endif


