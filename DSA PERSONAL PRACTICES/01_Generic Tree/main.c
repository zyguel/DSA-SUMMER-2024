/*********************************************************************************
* Problem: Finding the Deepest Node with the Maximum Sum Path                    *
*																				 *
* Objective: Write a function to find the deepest node in a generic N-ary tree   *
* that has the maximum sum from the root to that node. The function should       *
* return both the deepest node and the maximum sum path.                         *
*********************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		
	 // Initialize the tree with a root node
    TreeNode* root = initTree(1);

    // Create other nodes
    TreeNode* child1 = createNode(2);
    TreeNode* child2 = createNode(3);
    TreeNode* child3 = createNode(4);
    TreeNode* child4 = createNode(5);
    TreeNode* child5 = createNode(6);
//	TreeNode* child6 = createNode(7);
    // Build the tree structure
    addChild(root, child1);
    addChild(root, child2);
    addChild(child1, child3);
    addChild(child1, child4);
    addChild(child2, child5);
//	addChild(child5, child6);
    // Print the tree structure
    printf("Tree structure:\n");
    printTree(root, 0);

    // Find the deepest node with the maximum sum path
    Result result = findDeepestMaxSumNode(root);
    if (result.node != NULL) {
        printf("\nDeepest node with maximum sum path: %d\n", result.node->data);
        printf("Maximum sum: %d\n", result.maxSum);
    } else {
        printf("\nThe tree is empty.\n");
    }

    // Free the memory allocated for the tree
    freeTree(root);

	return 0;
}