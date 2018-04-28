#include "sort.h"

int main()
{
	int a[SIZE_TEST];
	getrand(a, SIZE_TEST);

	distCount(a, 0, SIZE_TEST - 1);
//	bubble(a, 0, SIZE_TEST - 1);
//	insertion(a, 0, SIZE_TEST - 1);
//	selection(a, 0, SIZE_TEST - 1);

	return 0;
}
