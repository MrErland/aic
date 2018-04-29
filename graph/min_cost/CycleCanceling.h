/*
function:最小费用流--消圈法
date:2017.8.28
https://blog.sengxian.com/algorithms/clearcircle
*/

#pragma once 
#ifdef Cycle

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 105, maxm = 105;
int N, M, bx[maxn], by[maxn], b[maxn], hx[maxm], hy[maxm], c[maxm], e[maxn][maxm];
int OriCost = 0, tot = 0;
struct edge { int to, cap, cost, rev; };

inline int ReadInt() 
{
	int n = 0, ch = getchar(); bool flag = false;
	while (ch < '0' || ch > '9') 
	{
		if (ch == '-') flag = true;
		ch = getchar();
	}
	do {
		n = n * 10 + ch - '0';
		ch = getchar();
	} while (ch >= '0' && ch <= '9');
	if (flag) return -n;
	return n;
}

inline int Cost(int i, int j) 
{
	return abs(bx[i] - hx[j]) + abs(by[i] - hy[j]) + 1;
}


struct MCMF {
	static const int maxNode = maxn + maxm + 2;
	vector<edge> G[maxNode];
	int dis[maxNode], prevv[maxNode], preve[maxNode], n;
	bool inq[maxNode], vis[maxNode];

	edge newedge(int t, int cap, int cost, int used)
	{
		edge e;
		e.to = t;
		e.cap = cap;
		e.cost = cost;
		e.rev = used;
		return e;
	}
	void add(int f, int t, int cap, int cost, int used) 
	{
		G[f].push_back(newedge(t, cap - used, cost, G[t].size()));
		G[t].push_back(newedge(f, used, -cost, G[f].size() - 1));
	}
	bool clearCircle() 
	{
		memset(dis, 0, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		int in = -1;
		for (int t = 0; t <= n; ++t)
			for (int cur = n - 1; cur >= 0 && in == -1; --cur)
			for (unsigned int i = 0; i < G[cur].size(); ++i)
			{
				edge &e = G[cur][i];
				if (e.cap > 0 && dis[e.to] > dis[cur] + e.cost)
				{
					dis[e.to] = dis[cur] + e.cost;
					prevv[e.to] = cur;
					preve[e.to] = i;
					if (t == n)
					{
						in = cur;
						break;
					}
				}
			}
		if (in == -1) return false; //没有找到负圈
		while (!vis[in]) 
		{
			if (vis[in] == true) break;
			vis[in] = true;
			in = prevv[in];
		}
		//开始消圈
		int cur = in;
		do {
			edge &e = G[prevv[cur]][preve[cur]];
			e.cap--;
			G[e.to][e.rev].cap++;
			cur = prevv[cur];
		} while (cur != in);
		return true;
	}
}MCMF;

void Solve() 
{
	int s = N + M, t = N + M + 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			MCMF.add(i, j + N, INF, Cost(i, j), e[i][j]);
	for (int i = 0; i < N; ++i)
		MCMF.add(s, i, b[i], 0, b[i]);
	for (int j = 0; j < M; ++j) 
	{
		int sum = 0;
		for (int i = 0; i < N; ++i) sum += e[i][j];
		MCMF.add(j + N, t, c[j], 0, sum);
	}
	MCMF.n = M + N + 2;
	while (MCMF.clearCircle())
	{
		printf("SUBOPTIMAL\n");
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				edge &e = MCMF.G[i][j];
				printf("%d%c", MCMF.G[e.to][e.rev].cap, j + 1 == M ? '\n' : ' ');
			}
	}
}


int main() {
	N = ReadInt(), M = ReadInt();
	for (int i = 0; i < N; ++i)
		bx[i] = ReadInt(), by[i] = ReadInt(), tot += (b[i] = ReadInt());
	for (int i = 0; i < M; ++i)
		hx[i] = ReadInt(), hy[i] = ReadInt(), c[i] = ReadInt();
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			OriCost += Cost(i, j) * (e[i][j] = ReadInt());
	Solve();
	return 0;
}

#endif
