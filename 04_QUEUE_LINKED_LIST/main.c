/********************************************************************************************************
* ACT_04 BASIC QUEUE																					*
* TYPE: QUEUE LINKED LIST																				*
* AUTHOR: ZYGUEL PHILIP CABOGOY BSIT-2																	*
* DSA TERM: SUMMER 2024																					*
* June 15, 2024																							*
*																										*
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "QueueLinkedList.h"
#ifdef _WIN32
    /* Windows-specific code */
    #define CLEAR_SCREEN "cls"
#else
    /* POSIX-compliant code */
    #define CLEAR_SCREEN "clear"
#endif
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* NOTE: SINGLE LINE COMMENTS COUNTS AS C++ Comments; it is restricted in this project to support all ANSI C program standards*/

int main(int argc, char *argv[]) {
	Queue *q = createQueue();
	message();
	printf("\n\n\n***PRESS ENTER TO CONTINUE***\n\n");
	getchar();
	system(CLEAR_SCREEN);
	Enqueue(q, 5);
	Enqueue(q, 10);
	Enqueue(q, 15);
    Enqueue(q, 20);
	printf("FRONT: %d\n", Front(*q));
 	printf("REAR: %d\n", Rear(*q));
 	displayQueue(*q);
	Dequeue(q);
	printf("UPDATED FRONT: %d\n", Front(*q));
	displayQueue(*q);
	return 0;
}

