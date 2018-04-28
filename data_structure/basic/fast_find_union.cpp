/*
function:查找合并
by：Erland
data：2017.6.20
*/

#include <iostream>
#include <vector>
using namespace std;

void fast_find()		//快速查找算法
{
	int a, b;
	vector <int> array;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		array.push_back(i);

	while (cin >> a >> b)
	{
		if (a == b)
			continue;
		for (int i = 0; i < n; i++)
		{
			if (array[i] == array[a])
			{
				array[i] = array[b];
			}
		}
		cout << a << " " << b << endl;
		for (int i = 0; i < n; i++)
			cout << array[i] << " ";
		cout << endl;
	}
}

void fast_union()		//快速合并算法
{
	int a, b;
	vector <int> array;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		array.push_back(i);

	while (cin >> a >> b)
	{
		int i, j;
		for (i = a; i != array[i]; i = array[i]);	//找到array[i]==i的位置，即树根
		for (j = b; j != array[j]; j = array[j]);
		if (i == j) continue;
		array[i] = j;

		cout << a << " " << b << endl;
		for (int i = 0; i < n; i++)
			cout << array[i] << " ";
		cout << endl;
	}
}

void fast_union_power()		//加权快速合并算法
{
	int a, b;
	vector <int> array;
	int power[100];
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		array.push_back(i), power[i] = 1;

	while (cin >> a >> b)
	{
		int i, j;
		for (i = a; i != array[i]; i = array[i])		//找到array[i]==i的位置，即树根
			array[i] = array[array[i]];						//等分路径压缩
		for (j = b; j != array[j]; j = array[j])
			array[j] = array[array[j]];
		if (i == j) continue;
		if (power[i] <= power[j])
		{
			array[i] = j;
			power[j] += power[i];
		}
		else{
			array[j] = i;
			power[i] += power[j];
		}

		cout << a << " " << b << endl;
		for (int i = 0; i < n; i++)
			cout << array[i] << " ";
		cout << endl;
	}
}

int main()
{
	fast_find();
//	fast_union();
//	fast_union_power();
	return 0;
}

