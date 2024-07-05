#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BFS.h"

int main(void){

	NodePtr root = NULL;
	Product p1 = {"[JS for Dummies]", 89000.2,20,{1,1,2024}};
	Product p2 = {"[HTML]", 80000.2,25,{1,1,2024}};
	Product p3 = {"[Iphone 15 PLUS]", 75000.5,30,{1,1,2024}};
	Product p4 = {"[DSA !EASY]", 7,40,{1,1,2024}};
	Product p5 = {"[Iphone RootKit]", 25500.69,21,{1,1,2024}};
	root = addNode(root, p1);
	root = addNode(root, p2);
	root = addNode(root, p3);
	root = addNode(root, p4);
	root = addNode(root, p5);
	
	printf("BFS TRAVERSAL:\n ");
	bfsTraversal(root);
		
	printf("\n\nDFS TRAVERSAL:\n ");
	inorderTraversal(root);
	
	return 0;
}
