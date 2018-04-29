/*
function:PFS Implement 随机化广义图搜索
by:Erland
date:2017.7.29
*/

#ifdef AdjList
#include "AdjList.h"

//随机队列ADT
#define Item Edge
static int N;
static Item *s;
void RQinit(int max)
{
	s = new Item[max];
	N = 0;
}
bool RQempty()
{
	return N == 0;
}
void RQupdate(Item x)
{}
void RQput(Item x)
{
	s[N++] = x;
}
Item RQget()
{
	Item t;
	int i = N*(rand() / (RAND_MAX + 1.0));
	t = s[i];
	s[i] = s[N - 1];
	s[N - 1] = t;
	return s[--N];
}


//随机搜索
void PFS(Graph G, Edge e)
{
	link t;
	int v, w;
	RQput(e);
	pre[e.w] = cnt++;
	while (!RQempty())
	{
		e = RQget();
		w = e.w;
		st[w] = e.v;
		for (t = G->adj[w]; t != NULL; t = t->next)
		{
			if (pre[v = t->v] == -1)
			{
				RQput(EDGE(w, v));
				pre[v] = cnt++;
			}
			else if (st[v] == -1)
				RQupdate(EDGE(w, v));
		}
	}
}


#endif

void graphSerachPFS(Graph G, int s)
{
	int v;
	cnt = 0;
	for (v = 0; v < G->V; v++)
		pre[v] = st[v] = -1;
	RQinit(maxV);
	PFS(G, EDGE(-1, s));
}
