#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int data;
    struct TreeNode** children;
    int childCount;
} TreeNode;

// Function prototypes
TreeNode* createNode(int data);
void addChild(TreeNode* parent, TreeNode* child);
void freeTree(TreeNode* root);
TreeNode* initTree(int rootData);
void printTree(TreeNode* root, int level);

typedef struct Result {
    TreeNode* node;
    int maxSum;
} Result;

Result findDeepestMaxSumNode(TreeNode* root);

#endif // TREE_H
