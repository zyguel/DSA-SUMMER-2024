/*********************************************************************************
* THIS PROGRAM IS ABOUT IMPLEMENTATION OF GRAPH - ADAJACENCY LIST USING ALPHABET *
* AUTHOR: ZYGUEL PHILIP CABOGOY													 *
* DATE OF CODE CREATION: JULY 16, 2024  										 *
*																				 *
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Graph graph;
	initAdjacencyList(&graph,26);
//	printf("Vertices: %d\n",graph.current_size);
	printf("Enter Vertices (Alphabet Only) their Connections (to terminate enter \"# #\") Example (\"A B\"): \n");    
    char vertice, edge;
    int rows = 0, cols = 0;
	while (1) {
        scanf(" %c %c", &vertice, &edge); // Add a space before %c to skip whitespace
        if (vertice == '#' && edge == '#') break; // Check for termination condition
        rows = calculateIndex(vertice); // Calculate Index could be kinda like a simple Hashing Function
        cols = calculateIndex(edge);
        addEdge(&graph,rows,cols); // Note: addVertex is implemented and called within addEdge
    }
	displayAdjacencyList(&graph);
	return 0;
}
