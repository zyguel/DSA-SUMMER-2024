#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#define MAX_VERTICES 26

typedef struct {
    int **matrix;
    int num_vertices;
} AdjacencyMatrix;

void initializeMatrix(AdjacencyMatrix *graph);
void addEdge(AdjacencyMatrix *graph, int rows, int cols);
void displayMatrix(AdjacencyMatrix *graph);
int calculateIndex(char a);
void freeMatrix(AdjacencyMatrix *graph);
#endif