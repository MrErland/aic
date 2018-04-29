
#pragma once
#define SIZE 10000000
#define NUM 50000
#define Item int
#define Key int
#define maxKey 100
#define NULLItem 0
#define INF 0x7fffffff
#define key(A) (A)
#define less(A,B) (key(A)<key(B))						//比较
#define equ(A, B) (key(A)==key(B))
#define exch(A,B) {Item t=A; A=B; B=t;}					//交换
#define compexch(A,B) if(less(B,A)) exch(A,B)			//让B不小于A

typedef struct BSTnode* link_bst;
static link_bst  head_bst, z_bst;
struct BSTnode{
	Item item;
	link_bst l, r;
	int N;
};

//RedBlackTree Node
typedef struct RBnode* link_rb;
static link_rb  head_rb, z_rb;
struct RBnode{
	Item item;
	link_rb l, r;
	int N;
	bool red;
};

//SkipList Node
typedef struct SKnode* link_sk;
static link_sk z_sk, head_sk, tail_sk;
struct SKnode{
	Item item;
	link_sk* next;
	int sz;
};
