/*
function:最小费用最大流的消环算法--网络单纯形
by:Erland
date:2017.8.24
*/

#pragma once 
#ifdef AdjList

#include "Item.h"
#include "AdjList.h"


#define C 0						//根的势
#define ST(i) st[i]->dup->v
#define Q (u->cap < 0 ? -u->flow : u->cap - u->flow)
#define R(u) (u->cost - phi[u->dup->v] + phi[u->v])
static int phi[maxV];			//保存顶点势
static int valid = 1;			//标志
static int mark[maxV] = { 0 };
const int M = 4, Co = 99;		//P.288



void addflow(link u, int d)
{
	u->flow += d;
	u->dup->flow -= d;
}

int phiR(link st[], int v)				//顶点势的计算
{
	if (ST(v) == v)
	{
		mark[v] = valid;
		return C;
	}
	if (mark[v] != valid)
		phi[v] = phiR(st, ST(v)) - st[v]->cost;
	mark[v] = valid;
	return phi[v];
}

int lca(link st[], int u, int v)		//找到(u,v)的最小祖先
{
	mark[u] = ++valid;		//小技巧,无需初始化
	mark[v] = valid;
	while (u != v)
	{
		u = ST(u);
		v = ST(v);
		if (u != ST(u) && mark[u] == valid)
			return u;
		mark[u] = valid;
		if (v != ST(v) && mark[v] == valid)
			return v;
		mark[v] = valid;
	}
	return u;
}

link augment(link st[], link x)			//增加流
{
	link u, cyc[maxV];
	int d, N, t;
	int i = x->v;
	int j = x->dup->v;
	t = lca(st, i, j);
	cyc[0] = x;
	N = 1;
	while (i != t)
	{
		cyc[N++] = st[i]->dup;
		i = ST(i);
	}
	while (j != t)
	{
		cyc[N++] = st[j];
		j = ST(j);
	}
	for (i = 0, d = C; i < N; i++)
	{
		u = cyc[i];
		d = Q > d ? d : Q;
	}
	for (i = 0; i < N; i++)
		addflow(cyc[i], d);
	for (i = 0; i < N - 1; i++)
	{
		u = cyc[N - 1 - i];
		if (Q == 0)
			return u;
	}
}


int onpath(link st[], int a, int b, int c)
{
	for (int i = a; i != c; i = ST(i))
	{
		if (i == b)
			return 1;
	}
	return 0;
}
void reverse(link st[], int u, int x)
{
	int i;
	do{
		i = st[u]->v;
		st[i] = st[u]->dup;
		u = i;
	} while (i != st[x]->v);
}
void update(link st[], link w, link y)
{
	int t, u = y->v, v = y->dup->v, x = w->v;
	if (st[x] != w->dup)
		x = w->dup->v;
	t = lca(st, u, v);
	if (onpath(st, u, x, t))
	{
		st[u] = y;
		reverse(st, u, x);
		return;
	}
	if (onpath(st, v, x, t))
	{
		st[v] = y->dup;
		reverse(st, v, x);
		return;
	}
}

void initial(Graph G, int s, int t, link st[])				//st[]有问题
{
	link u;
	int i, m[maxV] = { 0 };
	
	st[s] = G->adj[t]->dup;					//t是根结点
	phi[s] = 0;
	m[s] = 1;
	for (i = 0; i < G->V; i++)			//如果s不是0，使用队列即可
	{
		for (u = G->adj[i]; u != NULL; u = u->next)
		{
			if (m[u->v] == 0 && u->cap > 0)
			{
				phi[u->v] = phi[i] - u->cost;
				m[u->v] = 1;
				st[u->v] = u->dup;
			}
		}
	}
	st[t] = G->adj[t]->dup;
}

int graphMinCost(Graph G, int s, int t)
{
	int v;
	link u, x, st[maxV];
	graphInsertE(G, EDGE(s, t, M, M, Co));
	initial(G, s, t, st);
	for (valid = 1; valid++;)
	{
		for (v = 0; v < G->V; v++)
			phi[v] = phiR(st, v);
		for (v = 0, x = G->adj[v]; v < G->V; v++)
		{
			for (u = G->adj[v]; u != NULL; u = u->next)
			{
				if (Q > 0 && R(u) < R(x))
					x = u;
			}
		}
		if (R(x) == 0)
			break;
		update(st, augment(st, x), x);
	}
	return GraphCost(G);
}



int Rr(link st[], link u)
{
	return u->cost - phiR(st, u->dup->v) + phiR(st, u->v);
}
int GraphMinCost(Graph G, int s, int t)						//改进实现
{
	int v, old = 0;
	link u, st[maxV];
	graphInsertE(G, EDGE(s, t, M, M, Co));
	initial(G, s, t, st);
	for (valid = 1; valid != old; old = valid)
	{
		for (v = 0; v < G->V; v++)
		{
			for (u = G->adj[v]; u != NULL; u = u->next)
			{
				if (Q > 0 && Rr(st, u) < 0)
				{
					update(st, augment(st, u), u);
					valid++;
				}
			}
		}
	}
	return GraphCost(G);
}

#endif
