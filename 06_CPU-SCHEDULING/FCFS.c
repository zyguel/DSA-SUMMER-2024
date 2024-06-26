#include "FCFS.h"
#include <stdlib.h>

void sortProcessesByArrivalTime(Input *input) {
    int i, j;
    Process *temp;
    for (i = 0; i < input->size - 1; i++) {
        for (j = 0; j < input->size - i - 1; j++) {
            // If arrival times are different, sort by arrival time
            // If arrival times are the same, maintain original order
            if (input->p[j]->at > input->p[j + 1]->at || 
                (input->p[j]->at == input->p[j + 1]->at && j > j + 1)) {
                temp = input->p[j];
                input->p[j] = input->p[j + 1];
                input->p[j + 1] = temp;
            }
        }
    }
    input->front = 0;
    input->rear = input->size - 1;
}

void fcfs(Input *input) {
    int currentTime = 0;
    sortProcessesByArrivalTime(input);

    for (int i = input->front; i <= input->rear; i++) {
        if (currentTime < input->p[i]->at) {
            currentTime = input->p[i]->at;
        }
        input->p[i]->wt = currentTime - input->p[i]->at;
        input->p[i]->ct = currentTime + input->p[i]->bt;
        input->p[i]->tt = input->p[i]->ct - input->p[i]->at;
        currentTime = input->p[i]->ct;
    }
}