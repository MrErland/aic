#include <iostream>
#include "Knap.h"
using namespace std;

int main()
{
	int dp[CAP + 5] = { 0 };
	goods[0].size = 3;
	goods[0].val = 4;
	goods[1].size = 4;
	goods[1].val = 5;
	goods[2].size = 7;
	goods[2].val = 10;
	goods[3].size = 8;
	goods[3].val = 11;
	goods[4].size = 9;
	goods[4].val = 13;
	cout << knap(dp, CAP) << endl;

	return 0;
}
