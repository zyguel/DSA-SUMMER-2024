#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST

#include <stdbool.h>
typedef struct Node {
	int data;
	struct Node *link;
}SLL;

void initStack(SLL **top);
SLL* createNode(int data);

bool stack_pop(SLL **top);
bool stack_push(SLL **top, int data);
bool isEmpty(SLL *top);
//bool isFull(SLL *s);
int stack_peek(SLL *top);
void display(SLL *top);
void visualize(SLL *top);
  
#endif