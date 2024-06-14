/********************************************************************************************************
* ACT_03 BASIC STACK																					*
* TYPE: STACK LINKED LIST																				*
* AUTHOR: ZYGUEL PHILIP CABOGOY BSIT-2																	*
* DSA TERM: SUMMER 2024																					*
* June 13, 2024																							*
*																										*
********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkedList.h"

void initStack(SLL **top){
	*top = (SLL*)malloc(sizeof(SLL));
	if (*top == NULL) {
		printf("\nError Allocating Memory @initStack\n");
	}
	(*top)->data = -1;
	(*top)->link = NULL;
}

SLL* createNode(int data) {
    SLL* newNode = (SLL*)malloc(sizeof(SLL));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

bool stack_pop(SLL **top){
	if(!isEmpty(*top)){
		//SLL *temp = *top;
		*top = (*top)->link;
	
		return true;
	}
	return false;
}
bool stack_push(SLL **top, int data){
	SLL* nN = createNode(data); // nN refers to newNode
	if(*top == NULL || !nN){
		printf("\nError Allocating memory @stack_push\n");
		return false;
	}
	nN->link = *top;
	*top = nN;
	return true;
}

bool isEmpty(SLL *top){
	if(top->data == -1 && top->link == NULL){
		return true;
	}else {
		return false;
	}
}
//bool isFull(SLL *s);

int stack_peek(SLL *top){
	if(isEmpty(top)){
		return -1;
	}
	return top->data;
}
void display(SLL *top){
	if(isEmpty(top)){
		printf("\nNothing to Display Stack Link List is Empty\n");
		return;
	}
	SLL* temp = NULL;
	initStack(&temp);
	SLL* temp2 = top; 
	
	printf("\n\n<===BOTTOM ");
	while(!isEmpty(temp2)){
		stack_push(&temp, temp2->data);
		stack_pop(&temp2);
	}
	while(!isEmpty(temp)){
		printf("%d ", temp->data);
		stack_pop(&temp);
	}
	printf("TOP ===>\n\n");
	free(temp);
	free(temp2);
}
void visualize(SLL *top){
 	if(isEmpty(top)){ // Now compatible with the expected argument type
        printf("\n\nNothing to Visualize; STACK IS EMPTY!\n\n");
        return;
    }
    
      printf("__.....___................._._.........\n"
           "\\.\\.../.(_)___._..._..__._|.(_)_______.\n"
           ".\\.\\././|./.__|.|.|.|/._`\\.|.|.|_../._.\\\n"
           "..\\.V./.|.\\__.|.|_|.|(_|.|.|.|/./..__/\\\n"
           "...\\_/..|_|___/\\__,_\\__,_|_|_/___\\___|\\\n");

	       
    printf("\n\n\tINDEX\tDATA\tTOP\n");
    int i = 0; // Initialize index counter
    SLL *current = top; // Use a separate pointer to traverse the list
    while(current!= NULL){ // Loop continues as long as we haven't reached the end of the list
        printf("\t%d\t%d", i, current->data); // Print index and data
        if(current == top){ // Check if this is the top of the stack
            printf("\tTOP\n"); // Mark the top of the stack
        }
        current = current->link; // Move to the next node
        i++; // Increment index
        printf("\n");
    }

   
}