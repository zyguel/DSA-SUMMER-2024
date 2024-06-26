#include <stdio.h>
#include <stdlib.h>
#include "InputStruct.h"

// initialize Input structure with n processes
void initializeInput(Input *input, int n) {
    input->size = n;
    input->p = (Process**)malloc(n * sizeof(Process*));
    if (input->p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        input->p[i] = (Process*)malloc(sizeof(Process));
        if (input->p[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    input->front = 0;
    input->rear = n - 1;
}

// free allocated memory in processes
void freeInput(Input *input) {
    for (int i = 0; i < input->size; i++) {
        free(input->p[i]);
    }
    free(input->p);
}
