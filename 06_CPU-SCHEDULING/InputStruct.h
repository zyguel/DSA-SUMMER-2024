#ifndef INPUTSTRUCT_H
#define INPUTSTRUCT_H

typedef struct {
    int pid; // Process ID
    int bt;  // Burst Time
    int ct;  // Completion Time
    int at;  // Arrival Time
    int wt;  // Waiting Time
    int tt;  // Turn Around Time
} Process, *ProcessPtr;

typedef struct {
    int size;  // n processes
    Process **p;
    int front;
    int rear;
} Input;

void initializeInput(Input *input, int n);
void freeInput(Input *input);    

#endif