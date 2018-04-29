
#ifndef _basic_sort_
#define _basic_sort_

#include <stdlib.h>

#define SIZE_NUM 9999
#define SIZE_TEST 100
#define M (SIZE_NUM+5)			//数值范围
typedef int Item;
typedef Item* dataType;

#define key(A) (A)										//关键字
#define less(A,B) (key(A) < key(B))						//比较
#define exch(A,B) {Item t=A; A=B; B=t;}					//交换
#define compexch(A,B) if(less(B,A)) exch(A,B)			//让B不小于A

void getrand(Item*, int);

void selection(Item*, int, int);		// * 0 N-1
void insertion(Item*, int, int);
void bubble(Item*, int, int);
void distCount(int *, int, int);

#endif
