#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdjacencyList.h"
#define GREEN   "\x1B[32m" // Changes color to green
#define RESET   "\x1B[0m" // resets color to regulate printing of colored text

void initAdjacencyList(Graph *adjList, int initSize){
	adjList->current_size = 0;
	adjList->max_size = initSize;
	adjList->current_populated_vertex = (int *)calloc(26,sizeof(int));
	adjList->node = (NodePtr *) malloc(sizeof(NodePtr) * initSize);
	if(adjList->node == NULL) exit(0);
	int i; 
	for(i = 0; i < adjList->max_size; i++){
		adjList->node[i] = NULL;
	}	
}
NodePtr createNode(int vertex){
	NodePtr newNode = (NodePtr) malloc(sizeof(Node));
	if(newNode == NULL) exit(0);
	newNode->vertex = vertex;
	newNode->next = NULL;
	return newNode;
}

void addVertex(Graph *adjList, int index){
	adjList->current_populated_vertex[index] = 1;
	
}

void addEdge(Graph *adjList, int first_vertex, int second_vertex){
	if(first_vertex == second_vertex){
		printf("ILLEGAL CONNECTION!\n");
		return;
	} 
	
	if(adjList->current_populated_vertex[first_vertex] == 0){
		addVertex(adjList,first_vertex);
		adjList->current_size++;
	} 
	if(adjList->current_populated_vertex[second_vertex] == 0){
		addVertex(adjList,second_vertex);
		adjList->current_size++;
	}
	 
	NodePtr newNode = createNode(second_vertex);
    if (adjList->node[first_vertex] == NULL) {
        adjList->node[first_vertex] = newNode;
    } else {
        NodePtr trav = adjList->node[first_vertex];
        while (trav->next != NULL) {
            if (trav->vertex == second_vertex) {
                free(newNode); // Avoid memory leak
                return;
            }
            trav = trav->next;
        }
        if (trav->vertex == second_vertex) {
            free(newNode); // Avoid memory leak
            return;
        }
        trav->next = newNode;
    }
}

void displayAdjacencyList(Graph *adjList) {
    printf("\tADJACENCY LIST:::\n");
    for (int i = 0; i < adjList->max_size; i++) {
        if (adjList->current_populated_vertex[i] == 1) {
            NodePtr trav = adjList->node[i];
            printf("\tMATRIX[%c]: ", i + 65);
            while (trav != NULL) {
                printf("%s%c%s -> ", GREEN, trav->vertex + 65, RESET);
                trav = trav->next;
            }
            printf("NULL\n");
        }
    }
}
// You could also view this as a simple "hashing algorithm" where it returns an index
int calculateIndex(char a){
	if(a >= 'a' && a <= 'z') a -= 32;	
	return (int)a - 'A';	
}

