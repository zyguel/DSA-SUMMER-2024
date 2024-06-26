#include "GUI.h"
#include <stdio.h>

void displayTable(Input *input) {
    printf("+-----+------------+-------------+---------------+-------------+------------------+\n");
    printf("| PID | Burst Time | Arrival Time | Completion Time | Waiting Time | Turnaround Time |\n");
    printf("+-----+------------+-------------+---------------+-------------+------------------+\n");

    for (int i = 0; i < input->size; i++) {
        printf("| %3d | %10d | %11d | %15d | %11d | %16d |\n",
               input->p[i]->pid, input->p[i]->bt, input->p[i]->at,
               input->p[i]->ct, input->p[i]->wt, input->p[i]->tt);
    }

    printf("+-----+------------+-------------+---------------+-------------+------------------+\n");
}

void displayGanttChart(Input *input) {
    int totalTime = input->p[input->size - 1]->ct;
    int scale = (totalTime > 50) ? totalTime / 50 : 1;

    printf("\nGantt Chart:\n");

    // Top border
    printf("+");
    for (int i = 0; i < input->size; i++) {
        for (int j = 0; j < input->p[i]->bt / scale; j++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");

    // Process IDs
    printf("|");
    for (int i = 0; i < input->size; i++) {
        int spaces = input->p[i]->bt / scale;
        int pid_len = snprintf(NULL, 0, "P%d", input->p[i]->pid);
        int left_spaces = (spaces > pid_len) ? (spaces - pid_len) / 2 : 0;
        int right_spaces = (spaces > pid_len) ? (spaces - pid_len) - left_spaces : 0;

        for (int j = 0; j < left_spaces + 1; j++) printf(" ");
        if (spaces >= pid_len) {
            printf("P%d", input->p[i]->pid);
        } else {
            for (int j = 0; j < spaces; j++) printf(" ");
        }
        for (int j = 0; j < right_spaces; j++) printf(" ");
        printf("|");
    }
    printf("\n");

    // Bottom border
    printf("+");
    for (int i = 0; i < input->size; i++) {
        for (int j = 0; j < input->p[i]->bt / scale; j++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");

    // Time labels
    printf("0");
    int currentTime = 0;
    for (int i = 0; i < input->size; i++) {
        int spaces = input->p[i]->bt / scale;
        currentTime += input->p[i]->bt;
        int num_len = snprintf(NULL, 0, "%d", currentTime);

        for (int j = 0; j < spaces - num_len; j++) {
            printf(" ");
        }
        printf("%d", currentTime);
        if (i < input->size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
void displayAverages(Input *input) {
    int totalWT = 0, totalTAT = 0;
    float avgWT, avgTAT;

    for (int i = 0; i < input->size; i++) {
        totalWT += input->p[i]->wt;
        totalTAT += input->p[i]->tt;
    }

    avgWT = (float)totalWT / input->size;
    avgTAT = (float)totalTAT / input->size;

    printf("\nTotal Waiting Time: %d\n", totalWT);
    printf("Total Turnaround Time: %d\n", totalTAT);
    printf("Average Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
}
/*
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numProcesses, i;
    int burstTime[10];  // Assuming a maximum of 10 processes
    initscr();  // Initialize ncurses
    cbreak();   // Disable line buffering
    echo();     // Enable echoing of input characters

    // Draw the box
    mvprintw(2, 0, "+-----------------------------+");
    mvprintw(3, 0, "|  Number of Processes:       |");
    mvprintw(4, 0, "|                             |");
    mvprintw(5, 0, "|                             |");
    mvprintw(6, 0, "|                             |");
    mvprintw(7, 0, "|                             |");
    mvprintw(8, 0, "|                             |");
    mvprintw(9, 0, "|                             |");
    mvprintw(10, 0, "+----------------------------+");

    // Move the cursor to the input position
    move(3, 24);
    refresh();

    // Read number of processes
    scanw("%d", &numProcesses);

    // Get burst time for each process
    for (i = 0; i < numProcesses; i++) {
        move(4, 3);  // Move cursor to "Burst time: "
        printw("Burst time [%c]: ", i + 1 + 64);
        move(4, 19);  // Move cursor to input position
        refresh();
        scanw("%d", &burstTime[i]);
        // Clear the input area
        move(4, 19);
        clrtoeol();
        move(4, 30);
        printw("|");
        refresh();
    
    
    }

    endwin();  // Clean up ncurses

    return 0;
}
*/