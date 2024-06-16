#ifndef QUEUE_LINKED_LIST 
#define QUEUE_LINKED_LIST
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}Node, *NodePtr;

typedef struct {
	NodePtr front;
	NodePtr rear;
}Queue;

/* void initQueue(Queue *q); */
Queue* createQueue();
Node* newNode(int data);

bool Enqueue(Queue *q, int elem);
int Front(Queue q);
bool Dequeue(Queue *q);
int Rear(Queue q);

bool isEmpty(Queue q);

void displayQueue(Queue q);

void message();
#endif