/********************************************************************************************************
* ACT_03 BASIC STACK																					*
* TYPE: STACK ARRAY LIST																				*
* AUTHOR: ZYGUEL PHILIP CABOGOY BSIT-2																	*
* DSA TERM: SUMMER 2024																					*
* June 13, 2024																							*
*																										*
********************************************************************************************************/
#include <stdio.h>
#include "StackArray.h"
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
    // Windows-specific code
    #define CLEAR_SCREEN "cls"
#else
    // POSIX-compliant code
    #define CLEAR_SCREEN "clear"
#endif
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	message();
	printf("\nPress Enter to Proceed!\n");
	getchar();

	SAL s;
    initStack(&s);
	// YOU MAY COMMENT THE LINES BELOW IF YOU PREFER CALLING FUNCTIONS in MANUAL
	printf("\n**This is a CLI based application**\n");
    printf("type \".help\" to display all commands \n");
    char command[50];
    while (1) { // Main loop for CLI interaction
        printf("SAL command > ");
        fgets(command, sizeof(command), stdin); // Read user input

        // Remove trailing newline character
        command[strcspn(command, "\n")] = 0;

        // Simple command matching
        if (strcmp(command, "exit") == 0) {
            break; // Exit the loop if the user types "exit"
        } else if (strcmp(command, ".help") == 0) {
            printf("Available commands:\n");
            printf("  push <number> - Pushes a number onto the stack.\n");
            printf("  pop          - Pops a number from the stack.\n");
            printf("  peek         - Shows the top element of the stack.\n");
            printf("  empty        - Checks if the stack is empty.\n");
            printf("  full         - Checks if the stack is full.\n");
            printf("  display      - Displays stack from Bottom to Top without traversing.\n");
            printf("  visualize    - Visualizes stack through traversing and marks the Top element with \"TOP\"\n");
            printf("  cls          - Clears Console.\n");
            printf("  exit         - Exits the program.\n");
        } else if (strncmp(command, "push", 4) == 0) {
            int value;
            if (sscanf(command, "%*s %d", &value) == 1) {
                stack_push(&s, value);
                printf("Value %d pushed onto the stack.\n", value);
            } else {
                printf("Invalid argument for push command.\n");
            }
        } else if (strcmp(command, "pop") == 0) {
            if (!isEmpty(&s)) {
                int poppedValue = stack_pop(&s);
                printf("Popped value: %d\n", poppedValue);
            } else {
                printf("Stack is empty.\n");
            }
        } else if (strcmp(command, "peek") == 0) {
            if (!isEmpty(&s)) {
                printf("Top of the stack: %d\n", stack_peek(&s));
            } else {
                printf("Stack is empty.\n");
            }
        } else if (strcmp(command, "empty") == 0) {
            if (isEmpty(&s)) {
                printf("Stack is empty.\n");
            } else {
                printf("Stack is not empty.\n");
            }
        } else if (strcmp(command, "full") == 0) {
            if (isFull(&s)) {
                printf("Stack is full.\n");
            } else {
                printf("Stack is not full.\n");
            }
        } else if (strcmp(command, "cls") == 0) {
            system(CLEAR_SCREEN);
        } else if (strcmp(command, "display") == 0) {
            display(&s);
        } else if (strcmp(command, "visualize") == 0) {
            visualize(&s);
        } else {
            printf("Unknown command. Type \".help\" to know more info.\n");
        }
    }

	/*
	stack_push(&s,5);
	stack_push(&s,10);
	stack_push(&s,15);
	stack_push(&s,20);
	stack_push(&s,25);
	stack_push(&s,30);
	
	isEmpty(&s); // this is bool
	isFull(&s); // this is bool
	
	printf("\nTOP IS %d\n", stack_peek(&s));
	stack_pop(&s);
	// 30 is removed 25 is shown
	printf("\nTOP IS %d\n", stack_peek(&s));
	visualize(&s);
	display(&s);
	return 0;
	*/
}
