#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "QueueLinkedList.h"

/*
void initQueue(Queue *q){
	
}
*/
Queue* createQueue(){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
    return q;
}

Node* newNode(int data){
	Node *temp = (NodePtr)malloc(sizeof(Queue));
	temp->data = data;
	temp->next = NULL;
	return temp;
}


bool Enqueue(Queue *q, int elem){
	
	NodePtr temp = newNode(elem);
	
	if (temp == NULL){
		return false;
	}
	
	if(q->rear == NULL){
		q->front = q->rear = temp;
		return true;
	}
	
	q->rear->next = temp;
	q->rear = temp;
	
	return true;
}

int Front(Queue q){
	return (isEmpty(q)) ? -1 : q.front->data;
}

bool Dequeue(Queue *q){
	if (q->front == NULL){
		return false;
	}
		
	NodePtr temp = q->front;
	q->front = q->front->next;
	
	if(q->front == NULL){
	   q->rear = NULL;
	}
	
	free(temp);	
}

int Rear(Queue q){
	return (isEmpty(q)) ? -1 : q.rear->data;
}

bool isEmpty(Queue q){
	if(q.front == NULL && q.rear == NULL){
		true;
	}
	return false;
}

void displayQueue(Queue q){
	printf("\n\nDISPLAYING QUEUE...\n");
	printf("\nFront ==> ");
	while(q.front != NULL){
		printf("%d ",q.front->data);
		q.front = q.front->next;
	}
	printf("<== Rear\n\n");
}
void message(){
	printf(
        "   ____                           __ _       _            _     __ _     _   \n"
        "  /___ \\_   _  ___ _   _  ___    / /(_)_ __ | | _____  __| |   / /(_)___| |_ \n"
        " //  / / | | |/ _ \\ | | |/ _ \\  / / | | '_ \\| |/ / _ \\/ _` |  / / | / __| __|\n"
        "/ \\_/ /| |_| |  __/ |_| |  __/ / /__| | | | |   <  __/ (_| | / /__| \\__ \\ |_ \n"
        "\\___,_\\ \\__,_|\\___|\\__,_|\\___| \\____/_|_| |_|_|\\_\\___|\\__,_| \\____/_|___/\\__|\n"
        "                                                                            \n"
    );

    printf("   ___          _____                       _      ___      _   \n");
    printf("  / __\\_   _   / _  /_   _  __ _ _   _  ___| |    / __\\__ _| |__   ___   __ _  ___  _   _  \n");
    printf(" /__\\// | | |  \\// /| | | |/ _` | | | |/ _ \\ |   / /  / _` | '_ \\ / _ \\ / _` |/ _ \\| | | | \n");
    printf("/ \\/  \\ |_| |   / //\\ |_| | (_| | |_| |  __/ |  / /__| (_| | |_) | (_) | (_| | (_) | |_| | \n");
    printf("\\_____/\\__, |  /____/\\__, |\\__, |\\__,_|\\___|_|  \\____/\\__,_|_.__/ \\___/ \\__, |\\___/ \\__, | \n");
    printf("       |___/         |___/ |___/                                        |___/       |___/  \n");
}

