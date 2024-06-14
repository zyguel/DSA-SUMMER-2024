#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "StackArray.h"
#define MAX 20
void initStack(SAL *s){
	s->top = -1;
}

bool stack_pop(SAL *s){
	if(isEmpty(s)){
		printf("\n\nNothing to POP; STACK IS EMPTY!\n\n");
		return false;
	}		
	s->data[s->top] = 0;
	s->top--;
	//printf("\nPOP Successful!\n");
	return true;
}

bool stack_push(SAL *s, int elem){
	if(isFull(s)){
		printf("\n\nCan't PUSH; STACK IS FULL!\n\n");
		return false;
	}
	s->top++;
	s->data[s->top] = elem;
//	printf("\nPUSH elem %d Successful!\n", elem);
	return true;
}

bool isEmpty(SAL *s){
	return (s->top == -1) ? true : false; 
}

bool isFull(SAL *s){
	return (s->top >= 20) ? true : false;	
	
}


// gives the the value of top
int stack_peek(SAL *s){
	return s->data[s->top];
}


void display(SAL *s){
	SAL tempA = *s;
	SAL tempB;
	initStack(&tempB);
	if(isEmpty(s)){
		printf("\n\nNothing to Display; STACK IS EMPTY!\n\n");
		return;
	}
	int i;
	printf("\n\n<===BOTTOM ");
	while(!isEmpty(&tempA)){
		stack_push(&tempB,tempA.data[tempA.top]);
		stack_pop(&tempA);
	}
	while(!isEmpty(&tempB)){
		printf("%d ", tempB.data[tempB.top]);
		stack_pop(&tempB);
	}
	printf("TOP ===>\n\n");
}

void visualize(SAL *s){ // Adjusted to take a pointer
    if(isEmpty(s)){ // Now compatible with the expected argument type
        printf("\n\nNothing to Visualize; STACK IS EMPTY!\n\n");
        return;
    }
    int i;
      printf("__.....___................._._.........\n"
           "\\.\\.../.(_)___._..._..__._|.(_)_______.\n"
           ".\\.\\././|./.__|.|.|.|/._`\\.|.|.|_../._.\\\n"
           "..\\.V./.|.\\__.|.|_|.|(_|.|.|.|/./..__/\\\n"
           "...\\_/..|_|___/\\__,_\\__,_|_|_/___\\___|\\\n");
    printf("\n\n\tINDEX\tDATA\tTOP\n");
    for(i = 0; i <= s->top; i++){ // Ensure this loop iterates correctly
        printf("\t%d\t%d", i, s->data[i]); // Use -> operator to access members through a pointer
        if(s->data[i] == s->data[s->top]){
            printf("\tTOP = %d",s->data[s->top]);
        }
        printf("\n");
    }
}

void message(){

    puts(" __  ____   __  ____ _____  _    ____ _  __      \n"
           "|  \/  \\ \\ / / / ___|_   _|/ \\  / ___| |/ /      \n"
           "| |\\/| |\\ V /  \\___ \\ | | / _ \\| |   | ' /       \n"
           "| |  | | | |    ___) || |/ ___ \\ |___|. \\       \n"
           "|_|  |_| |_|   |____/ |_/_/   \\_\\____|_\\_\\      \n"
           "                                                  \n"
           " ______   __  _______   ______ _   _ _____ _     \n"
           "| __ ) \\ / / |__  /\\ \\ / / ___| | | | ____| |    \n"
           "|  _ \\ V /    / /  \\ V / |  _| | | |  _| | |    \n"
           "| |_) || |    / /_   | || |_| | |_| | |___| |___ \n"
           "|____/ |_|   /____|  |_| \\____|\\___/|_____|_____|\n"
           "                                                  \n"
           " ____    _    ____   ___   ____  _____   __     \n"
           "/ ___|  / \\  | __ ) / _ \\ / ___|/ _ \\ \\ / /     \n"
           "| |    / _ \\ |  _ \\| | | | |  _| | | \\ V /      \n"
           "| |___/ ___ \\| |_) | |_| | |_| | |_| || |       \n"
           "\\____/_/   \\\\_\\____/ \\___/ \\____|\\___/ |_|\n");



}
