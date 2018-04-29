/*
function:Dinic算法求解最大流
http://www.lai18.com/content/1076206.html
*/

#ifdef Blog

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 105;
const int INF = 1 << 30;

struct Edge
{
	int to, cap;
};
int n, m, s, t, np, nc;
vector<Edge> edge;
vector<int>  G[MAXN];
int d[MAXN], cur[MAXN];

void AddEdge(int from, int to, int cap)
{
	edge.push_back((Edge){ to, cap });//这里调用了结构体缺省的构造函数，代码很简洁，下面也是
	edge.push_back((Edge){ from, 0 });
	int id = edge.size();
	G[from].push_back(id - 2);
	G[to].push_back(id - 1);
}

//bfs函数我做了调整，用距离标号数组d代替了书中的vis数组。另外d[s]改成了1，这个不影响。
bool bfs()
{
	memset(d, 0, sizeof(d));
	queue<int> Q;
	Q.push(s);
	d[s] = 1;
	while (!Q.empty())
	{
		int x = Q.front(); Q.pop();
		if (x == t) return true;
		for (int i = 0; i<G[x].size(); i++)
		{
			Edge& e = edge[G[x][i]];
			if (!d[e.to] && e.cap>0)//邻接点未访问且该边残量不为零
			{
				d[e.to] = d[x] + 1;
				Q.push(e.to);
			}
		}
	}
	return false;
}

int dfs(int x, int a)//x是当前遍历的点，a是目前为止所有弧的最小残量
{
	if (x == t || a == 0) return a;
	int flow = 0, f;
	for (int& i = cur[x]; i<G[x].size(); i++)//使用引用变量在遍历x所有邻接点的同时顺便修改了cur[x]的值，实现得很妙
	{
		Edge& e = edge[G[x][i]];
		if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap)))>0)
		{
			e.cap -= f;
			edge[G[x][i] ^ 1].cap += f;//^1 是定位残量网络中反向边的方法
			flow += f;
			a -= f;
			if (a == 0) break;
		}
	}
	return flow;
}

int Maxflow()//dinic
{
	int flow = 0;
	while (bfs())
	{
		memset(cur, 0, sizeof(cur));
		flow += dfs(s, INF);
	}
	return flow;
}

int main()
{
	char str[20];
	int u, v, w;
	while (scanf("%d%d%d%d", &n, &np, &nc, &m) != EOF)
	{
		s = n + 1;
		t = n + 2;
		for (int i = 0; i<n + 2; i++) G[i].clear();
		edge.clear();
		for (int i = 0; i<m; i++)//读入边信息
		{
			scanf("%s", str);
			sscanf(str, "%*c%d%*c%d%*c%d", &u, &v, &w);
			AddEdge(u, v, w);
		}
		for (int i = 0; i<np; i++)//读入源点信息
		{
			scanf("%s", str);
			sscanf(str, "%*c%d%*c%d", &u, &w);
			AddEdge(s, u, w);
		}
		for (int i = 0; i<nc; i++)//读入汇点信息
		{
			scanf("%s", str);
			sscanf(str, "%*c%d%*c%d", &u, &w);
			AddEdge(u, t, w);
		}
		printf("%d\n", Maxflow());
	}
	return 0;
}

#endif
