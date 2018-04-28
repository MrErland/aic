/*
function:分治法求数组最大值，效率高于直接遍历整个数组
by:Erland
date:2016.7.26
*/

#include <iostream>
using namespace std;
typedef int Item;

Item max(Item *a, int l, int r)
{
	Item u, v;
	int m = (l + r) / 2;
	if (l == r) return a[l];
	u = max(a, l, m);
	v = max(a, m + 1, r);
	if (u > v) return u;
	else return v;
}

int main()
{
	int a[10] = { 1, 5, 7, 12, 76, 32, 67, 34, 8, 9 };
	cout << max(a, 0, 9) << endl;
	return 0;
}
