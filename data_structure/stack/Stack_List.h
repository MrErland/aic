/******************Stack Implementation By LInkedList***************/

#ifndef _stack_by_list_
#define _stack_by_list_

typedef int Item;
typedef struct Stack* Pstack;
typedef struct StackNode* link;
typedef struct Stack* Pstack;

struct Stack{ link head; int size;};
struct StackNode{ Item item; link next;};

link Insert(Item, link);		//在next之前插入一个值为item的点
Pstack initStack();
bool Empty(Pstack);
void PushStack(Pstack, Item);
Item PopStack(Pstack);

#endif
