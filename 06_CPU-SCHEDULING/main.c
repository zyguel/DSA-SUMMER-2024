#include <stdio.h>
#include <stdlib.h>
#include "InputStruct.h"
#include "FCFS.h"
#include "GUI.h"

int main() {
   int n, i;
    Input input;

    printf("Welcome to FCFS!\n");
    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input for number of processes\n");
        return 1;
    }

    initializeInput(&input, n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Process %d:\n", i + 1);
        input.p[i]->pid = i + 1;
        printf("Burst Time: ");
        if (scanf("%d", &input.p[i]->bt) != 1 || input.p[i]->bt < 0) {
            fprintf(stderr, "Invalid input for burst time\n");
            freeInput(&input);
            return 1;
        }
        printf("Arrival Time: ");
        if (scanf("%d", &input.p[i]->at) != 1 || input.p[i]->at < 0) {
            fprintf(stderr, "Invalid input for arrival time\n");
            freeInput(&input);
            return 1;
        }
    }

    fcfs(&input);
    
    printf("\nFCFS Scheduling Results:\n");
    displayTable(&input);
    displayGanttChart(&input);
    displayAverages(&input);

    freeInput(&input);
    return 0;
}