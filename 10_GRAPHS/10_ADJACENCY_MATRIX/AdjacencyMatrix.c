#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyMatrix.h"

#define GREEN   "\x1B[32m"
#define RESET   "\x1B[0m"


void initializeMatrix(AdjacencyMatrix *graph) {
    graph->num_vertices = 26; // Example number of vertices
    graph->matrix = malloc(graph->num_vertices * sizeof(int*)); // Allocate memory for rows
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->matrix[i] = malloc(graph->num_vertices * sizeof(int)); // Allocate memory for columns
        for (int j = 0; j < graph->num_vertices; j++) {
            graph->matrix[i][j] = 0; // Initialize all elements to 0
        }
    }
}
void addEdge(AdjacencyMatrix *graph, int rows, int cols){
	if (rows >= 0 && rows < graph->num_vertices && cols >= 0 && cols < graph->num_vertices) {
        graph->matrix[rows][cols] = 1;
        // For undirected graph, uncomment the line below
        // graph->matrix[cols][row] = 1;
    } else {
        printf("Invalid vertex index! Row: %d Cols: %d, Vertices: %d\n", rows,cols, graph->num_vertices);
    }
}
void displayMatrix(AdjacencyMatrix *graph){
	int i, j;
	printf("Matrix[#]: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
    for (i = 0; i <= graph->num_vertices - 1; i++) {
        printf("Matrix[%c]: ", i+65);
        for (j = 0; j <= graph->num_vertices - 1; j++) {
          	if (graph->matrix[i][j] == 1) {
		        printf("%s%d%s ", GREEN, graph->matrix[i][j], RESET);
		    } else {
		        printf("%d ", graph->matrix[i][j]);
		    }
        }
        printf("\n");
    }
}

int calculateIndex(char a) {
    if (a >= 'a' && a <= 'z') {
        a = a - 32; // Convert lowercase to uppercase
    }
    return (int)a - 'A'; // Calculate index based on 'A'
}

void freeMatrix(AdjacencyMatrix *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
}