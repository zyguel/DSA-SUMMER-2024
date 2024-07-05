#ifndef BFS_H
#define BFS_H

typedef struct {
	int day, month, year;
} Date;

typedef struct {
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
} Product;

typedef struct node{
	Product item;
	struct node *left, *right;
} NodeType, *NodePtr;

// Queue for BFS
typedef struct QueueNode {
	NodePtr treeNode;
	struct QueueNode *next;
} QueueNode;

typedef struct {
	QueueNode *front, *rear;	
} Queue;

Queue *createQueue();
void enqueue(Queue *q, NodePtr treeNode);
NodePtr dequeue(Queue *q);
int isEmpty(Queue *q);
NodePtr createNode(Product item);
NodePtr addNode(NodePtr root, Product item);
NodePtr findMin(NodePtr root);
NodePtr deleteNode(NodePtr root, char *prodName);
void inorderTraversal(NodePtr root);
void bfsTraversal(NodePtr root);
#endif
