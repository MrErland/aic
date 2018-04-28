#ifndef _shell_sort_
#define _shell_sort_

#include "sort.h"

void shellsort(Item* a, int l, int r)
{
	int i, j, h;
	Item v;
	for (h = 1; h <= (r - 1) / 9; h = 3 * h + 1);		//计算步长:1,4,13,40,121,364,1093,3280,9841...
	for (; h > 0; h /= 3)
	{
		for (i = l + h; i <= r; i++)
		{
			j = i;
			v = a[i];
			while (j >= l + h && less(v, a[j - 1]))
			{
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = v;
		}
	}
}

#endif
