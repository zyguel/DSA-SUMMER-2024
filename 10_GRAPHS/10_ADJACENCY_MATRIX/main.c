#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdjacencyMatrix.h"


int main(void) {
	AdjacencyMatrix graph;
	initializeMatrix(&graph);
	printf("Vertices: %d\n",graph.num_vertices);
	printf("Enter Vertices (Alphabet Only) their Connections (to terminate enter \"# #\") Example (\"A B\"): \n");    
    char vertice, edge;
    int rows = 0, cols = 0;
	
	while (1) {
        scanf(" %c %c", &vertice, &edge); // Add a space before %c to skip whitespace
        if (vertice == '#' && edge == '#') break; // Check for termination condition
        rows = calculateIndex(vertice); // Calculate Index could be kinda like a simple Hashing Function
        cols = calculateIndex(edge);
        addEdge(&graph,rows,cols);
    }
    displayMatrix(&graph);
    freeMatrix(&graph);
    return 0;
}