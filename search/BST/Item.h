#pragma once

#define Item int
#define Key int
#define maxKey 100
#define NULLItem -1
#define SIZE 10000000
#define NUM 250000
#define key(A) (A)
#define less(A,B) (key(A)<key(B))						//比较
#define eq(A, B) (key(A)==key(B))
#define exch(A,B) {Item t=A; A=B; B=t;}					//交换
#define compexch(A,B) if(less(B,A)) exch(A,B)			//让B不小于A
