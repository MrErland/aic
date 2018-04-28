/*背包问题 动态规划+递归*/

#define N 5		//货物的数量
#define CAP 200		// 容量
typedef struct { int size; int val;}Goods;
static Goods goods[N];

int knap(int *dp, int cap)	
{
	int i, space, max, t;
	if (dp[cap] != 0) return dp[cap];
	for (i = 0, max = 0; i < N; i++)
	{
		if ((space = cap - goods[i].size) >= 0)
		{
			if ((t = knap(dp, space) + goods[i].val) > max)
				max = t;
		}
	}
	dp[cap] = max;
	return max;
}
