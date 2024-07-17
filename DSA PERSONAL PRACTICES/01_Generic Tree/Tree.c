#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Tree.h"
TreeNode* createNode(int data){
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->childCount = 0;
	newNode->children = NULL;
	return newNode;
}
void addChild(TreeNode* parent, TreeNode* child){
	parent->childCount++;
	parent->children = (TreeNode**)realloc(parent->children, parent->childCount * sizeof(TreeNode*));
	parent->children[parent->childCount - 1] = child;
	
}
void freeTree(TreeNode* root){
	if(root == NULL){
		return;
	}
	int i;
	for(i = 0; i < root->childCount; i++){
		free(root->children[i]); // This will include children of a child;
	}
	free(root->children);
	free(root);
}

TreeNode* initTree(int rootData){
	return createNode(rootData);
}

void printTree(TreeNode* root, int level) {
    if (root == NULL) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%d\n", root->data);
    for (int i = 0; i < root->childCount; i++) {
        printTree(root->children[i], level + 1);
    }
}

// Find the deepest node with the maximum sum path

/*
	Weakness of this implementation is that it errors if more
	than 1 deepest leaf nodes are equal to each other.

*/
Result findDeepestMaxSumNode(TreeNode* root) {
    Result res = {NULL, 0};
    if (root == NULL) return res;

    typedef struct {
        TreeNode* node;
        int depth;
        int sum;
    } StackElement;

    StackElement stack[1000];
    int top = -1;

    stack[++top] = (StackElement){root, 0, root->data};

    while (top >= 0) {
        StackElement current = stack[top--];

        if (current.depth > (res.node ? res.node->data : -1) || 
           (current.depth == (res.node ? res.node->data : -1) && current.sum > res.maxSum)) {
            res.node = current.node;
            res.maxSum = current.sum;
        }

        for (int i = 0; i < current.node->childCount; i++) {
            TreeNode* child = current.node->children[i];
            stack[++top] = (StackElement){child, current.depth + 1, current.sum + child->data};
        }
    }

    return res;
}