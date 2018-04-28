/*
function:寻找10000以内的所有素数（埃拉托色尼筛法）
by:Erland
date:2017.6.21
*/

#include <iostream>
using namespace std;

int main()
{
	const int N = 10000;
	int i, j;
	int a[N];
	for (i = 2; i < N; i++) a[i] = 1;
	for (i = 2; i < N; i++)
	{
		if (a[i])
		{
			for (j = i; i*j < N; j++)
				a[i*j] = 0;
		}
	}
	for (i = 2; i < N; i++)
	{
		if (a[i])
			cout << i << " ";
	}
	return 0;
}


