#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	int data[MAX];
	int front ;
	int rear;
	
}circularQ;


circularQ* create_cQ();
void enque(circularQ *cq, int data); // insert rear (0(1))
void deque(circularQ *cq); // Delete Front (0(1))
int front(circularQ cq);
int rear(circularQ cq);
int isEmpty(circularQ cq);

int isFull(circularQ cq);

void display(circularQ *cq); 

int main (int argc, char *argv[]){
	circularQ *cq = create_cQ(); 
	enque(cq, 5);
	enque(cq, 10);
	enque(cq, 15);
	enque(cq, 20);
	
	display(cq);
	deque(cq);
	display(cq);
}


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
	printf("\n Deleted -> %d\n", cq->data[cq->front]);
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
		printf("Nothing to display circular q is empty!\n");
	}
	int i = cq->front, j = cq->rear;
	printf("\n Front ==> %d \n", cq->data[i]);
	printf(" DATA : ");
	for (; i != j; i = (i + 1) % MAX){
		printf("%d ", cq->data[i]);
	}
	printf("\n Rear ==>  %d\n", cq->data[j]);
}


