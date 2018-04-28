/*
function:欧几里得算法(求两个数的最大公因子)
by:Erland
date:2017.6.26
*/

#include <iostream>
using namespace std;

int gcd(int m, int n)
{
	if (n == 0) return m;
	return gcd(n, m%n);
}

int main()
{
	int s, t;
	cin >> s >> t;
	cout << gcd(s, t);
	return 0;
}
