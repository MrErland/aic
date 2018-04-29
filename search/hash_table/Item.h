#pragma once

#define SIZE 10000000
#define NUM 100000
#define Item int
#define Key int
#define maxKey 1000
#define NULLItem 0
#define INF 0x7fffffff
#define key(A) (A)
#define less(A,B) (key(A)<key(B))						//比较
#define equ(A, B) (key(A)==key(B))
#define exch(A,B) {Item t=A; A=B; B=t;}					//交换
#define compexch(A,B) if(less(B,A)) exch(A,B)			//让B不小于A


