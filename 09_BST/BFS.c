#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BFS.h"


Queue *createQueue() {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
		
}

void enqueue(Queue *q, NodePtr treeNode){
	QueueNode *newNodeQueue = (QueueNode *)malloc(sizeof(QueueNode));
	newNodeQueue->treeNode = treeNode;
	newNodeQueue->next = NULL;
	if(q->rear == NULL){
		q->front = q->rear = newNodeQueue;
		return;
	}
	q->rear->next = newNodeQueue;
	q->rear = newNodeQueue;
}

NodePtr dequeue(Queue *q){
	if(q->front == NULL) return NULL;
	QueueNode *temp = q->front;
	NodePtr treeNode = temp->treeNode;
	q->front = q->front->next;
	if(q->front == NULL) q->rear = NULL;
	free(temp);
	return treeNode;
}

int isEmpty(Queue *q){
	return q->front == NULL;
}


// BST functions
NodePtr createNode(Product item){
	NodePtr newNodeTree = (NodePtr)malloc(sizeof(NodeType));
	newNodeTree->item = item;
	newNodeTree->left = newNodeTree->right = NULL;
	return newNodeTree;	
}

NodePtr addNode(NodePtr root, Product item){
	if(root == NULL) return createNode(item);
	if(strcmp(item.prodName, root->item.prodName) < 0){
		root->left = addNode(root->left,item);
	}else if (strcmp(item.prodName, root->item.prodName) > 0){
		root->right = addNode(root->right, item);
	}
	return root;
}

NodePtr findMin(NodePtr root){
	while(root->left != NULL) root = root->left;
	return root;	
}

NodePtr deleteNode(NodePtr root, char *prodName){
	if(root == NULL) return root;
	if(strcmp(prodName, root->item.prodName) < 0){
		root->left = deleteNode(root->left, prodName);
	}else if (strcmp(prodName, root->item.prodName > 0)){
		root->right = deleteNode(root->right, prodName);
	}else{
		if(root->left == NULL){
			NodePtr temp = root->right;
			free(root);
			return temp;
		} else if(root->right == NULL){
			NodePtr temp = root->left;
			free(root);
			return temp;
		}
		NodePtr temp = findMin(root->right);
		root->item = temp->item;
		root->right = deleteNode(root->right,temp->item.prodName);
	}
	return root;
}

// DFS : Inorder
void inorderTraversal(NodePtr root){
	if (root != NULL){
		inorderTraversal(root->left);
		printf("%s ", root->item.prodName);
		inorderTraversal(root->right);
	}
}

void bfsTraversal(NodePtr root){
	if(root == NULL) return;
	Queue *q = createQueue();
	enqueue(q, root);
	while(!isEmpty(q)){
		NodePtr currentNode = dequeue(q);
		printf("%s ", currentNode->item.prodName);
		if(currentNode->left != NULL) enqueue(q, currentNode->left);
		if(currentNode->right != NULL) enqueue(q, currentNode->right);
	}
}


