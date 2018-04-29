/*
function:DAG的拓扑排序
by:Erland
date:2017.8.8
*/


//重新排列法
#ifdef AdjList

//逆拓扑排序——ts[]
#include "AdjList.h"
#define Dag Graph
static int cnt_ts;
static int pre_ts[maxV];

void dfsTsR(Dag D, int v, int ts[])
{
	link t;
	pre_ts[v] = 0;
	for (t = D->adj[v]; t != NULL; t = t->next)
	{
		if (pre_ts[t->v] == -1)
			dfsTsR(D, t->v, ts);
	}
	ts[cnt_ts++] = v;
}
void DagTS(Dag D, int ts[])
{
	int v;
	cnt_ts = 0;
	for (v = 0; v < D->V; v++)
	{
		ts[v] = -1;
		pre_ts[v] = -1;
	}
	for (v = 0; v < D->V; v++)
	{
		if (pre_ts[v] == -1)
			dfsTsR(D, v, ts);
	}
}


#endif


#ifdef AdjMatrix

//拓扑排序
#include "AdjMatrix.h"
#define Dag Graph
static int cnt_ts;
static int pre_ts[maxV];

void dfsTsR(Dag D, int v, int ts[])
{
	int w;
	pre_ts[v] = 0;
	for (w = 0; w < D->V; w++)
	{
		if (D->adj[w][v] != 0 && pre_ts[w] == -1)
			dfsTsR(D, w, ts);
	}
	ts[cnt_ts++] = v;
}
void DagTS(Dag D, int ts[])
{
	int v;
	cnt_ts = 0;
	for (v = 0; v < D->V; v++)
	{
		ts[v] = -1;
		pre_ts[v] = -1;
	}
	for (v = 0; v < D->V; v++)
	{
		if (pre_ts[v] == -1)
			dfsTsR(D, v, ts);
	}
}

#endif


//重新编号法
#ifdef AdjList

#define QueueMatrix
#include "Queue.h"
static int in[maxV];

void DagTs_Queue(Dag D, int ts[])
{
	int i, v;
	link t;
	for (v = 0; v < D->V; v++)
	{
		in[v] = 0;
		ts[v] = -1;
	}
	for (v = 0; v < D->V; v++)			//计算各顶点入度
	{
		for (t = D->adj[v]; t != NULL; t = t->next)
			in[t->v]++;
	}
	InitQue(D->V);
	for (v = 0; v < D->V; v++)			//源点入队
	{
		if (in[v] == 0)
			PutQue(v);
	}
	for (i = 0; !EmptyQue(); i++)
	{
		ts[i] = (v = GetQue());
		for (t = D->adj[v]; t != NULL; t = t->next)
		{
			if (--in[t->v] == 0)
				PutQue(t->v);
		}
	}
}


#endif
