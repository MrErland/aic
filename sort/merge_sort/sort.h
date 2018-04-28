#pragma once
#include <stdlib.h>

typedef int Item;
typedef Item* dataType;
typedef struct listNode* listN;
struct listNode{ Item item; listN next; };

#define key(A) (A)						//关键字
#define less(A,B) (key(A)<key(B))				//比较
#define exch(A,B) {Item t=A; A=B; B=t;}				//交换
#define compexch(A,B) if(less(B,A)) exch(A,B)			//让B不小于A

void getrand(Item*, int);
