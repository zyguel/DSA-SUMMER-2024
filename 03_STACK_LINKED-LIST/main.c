#include <stdio.h>
#include <stdlib.h>
#include "StackLinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(){

	SLL *top = NULL;
	initStack(&top);
	if(isEmpty(top)){
		printf("STACK IS EMPTY\n");
		display(top);
	}
	stack_push(&top, 5);
	stack_push(&top, 10);
	stack_push(&top, 15);
	stack_push(&top, 25); 
	printf("TOP: %d", stack_peek(top));
	display(top);
	stack_pop(&top);
	printf("TOP: %d", stack_peek(top));
	display(top);
	visualize(top);
	free(top);
	exit(1);
}