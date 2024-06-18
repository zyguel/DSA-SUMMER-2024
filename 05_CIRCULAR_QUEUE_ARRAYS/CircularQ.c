#include <stdio.h>
#include <stdlib.h>
#include "CircularQ.h"
#define MAX 10
// If index is set to -1 then it means emnpty or no data yet
circularQ* create_cQ(){
	circularQ *new_cq = (circularQ*) malloc(sizeof(circularQ));
	new_cq->front = new_cq->rear = -1;
	return new_cq;
}

// 
void enque(circularQ *cq, int data){
	if(isFull(*cq)){
		printf("QUEUE is FULL\n\n");
	}else{
		if(cq->front == -1) cq->front = 0;
		cq->rear = (cq->rear + 1) % MAX;		
		cq->data[cq->rear] = data;\
		printf("\n Inserted -> %d\n", data);			
	}	
}

void deque(circularQ *cq){
	int elem;
	if(isEmpty(*cq)){
		printf("QUEUE is EMPTY");
	}else{
		elem =  cq->data[cq->front];
		if(cq->front == cq->rear){
			cq->data[cq->rear] = -1; 
			cq->front = cq->rear = -1;
		}else{
			cq->front = (cq->front + 1) % MAX;
		}
	}
	printf("\n Deleted -> %d\n", elem);
}

int front(circularQ cq){
	return (!isEmpty(cq)) ? cq.data[cq.front] : -1;
}

int rear(circularQ cq){
	return (!isEmpty(cq)) ? cq.data[cq.rear] : -1;
}

int isEmpty(circularQ cq){
	return (cq.front == -1 && cq.rear == -1) ? 1 : 0;
}

int isFull(circularQ cq){
	if ((cq.front == cq.rear + 1) || (cq.front == 0 && cq.rear == MAX - 1)){
		return 1;	
	}
	return 0;
}

void display(circularQ *cq){
	if(isEmpty(*cq)){
		printf("\n Nothing to display circular q is empty!\n\n");
		return;
	}
	int i;
	printf("\n Front ==> %d \n", cq->data[cq->front]);
	printf(" DATA : ");
	for (i = cq->front; i != cq->rear; i = (i + 1) % MAX){
		printf("%d ", cq->data[i]);
	}
	printf("%d ", cq->data[i]);
	printf("\n Rear ==>  %d\n", cq->data[cq->rear]);
}
