#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "StackArray.h"

void initStack(SAL *s){
	
	s->top = -1;
	memset(s->data, 0, sizeof(s->data));
	
}

bool stack_pop(SAL *s){
	
	if(isEmpty(s)){
		printf("\n\nNothing to POP; STACK IS EMPTY!\n\n");
		return false;
	}		
	s->data[s->top] = 0;
		s->top--;
	printf("\n\nPOP Successful!\n\n");
	return true;
	
}

bool stack_push(SAL *s, int elem){
	
	if(isFull(s)){
		printf("\n\nCan't PUSH; STACK IS FULL!\n\n");
		return false;
	}
		
	s->data[s->top++] = elem;
	return true;
	
}

bool isEmpty(SAL s){
	
	return (s.top == -1) ? true : false; 
	
}

bool isFull(SAL s){
	
	return (s.top >= MAX) ? true : false;	
	
}


// gives the the value of top
int stack_peek(SAL *s){
	
	return s->data[s->top];
	
}


void display(SAL s){
	
}

void visualize(SAL s){
	
}
