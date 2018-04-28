/***********************************Tree Implementation****************/

#ifndef _tree_
#define _tree_

typedef int Item;
typedef struct tree* node;
struct tree{ Item item; node l; node r;};

void visit(node);	
void visit(Item);
void traversePre(node);
void traverseIn(node);
void traversePost(node);

//非递归实现前序遍历
void traverse(node);

int getDepth(node);
int getWidth(node);
node initTree(int);
int count(node);

node Newnode(Item, node, node);
node max(Item[], int, int);

#endif
