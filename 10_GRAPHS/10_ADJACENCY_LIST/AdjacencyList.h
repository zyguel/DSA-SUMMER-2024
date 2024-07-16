#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

typedef struct node {
	int vertex;
	struct node* next;		
}Node, *NodePtr;

typedef struct {
	int *current_populated_vertex;
	int max_size;
	int current_size; // shows current number of vertices;
	NodePtr *node;
} Graph;

void initAdjacencyList(Graph *adjList, int initSize);
NodePtr createNode(int vertex);
void addVertex(Graph *adjList, int vertex);
void addEdge(Graph *adjList, int first_vertex, int second_vertex);
void displayAdjacencyList(Graph *adjList); 
int calculateIndex(char a);

#endif
