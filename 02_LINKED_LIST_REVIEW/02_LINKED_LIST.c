/***********************************************************************
*	DSA SUMMER 2024
*	ACTIVITY: REVIEW ON LINKED LIST
*	CODE BY: ZYGUEL PHILIP CABOGOY 
*	STUDENT NUMBER: 11300246
*	DATE OF CODE PRODUCTION: JUNE 11, 2024					
************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char name[20];
	int idNum;
	int age;
}info;


typedef struct node {
	info data;
	struct node* next;
	
}Node, *NodePtr;

//Function prototypes

void insert_front(NodePtr* head);
void insert_end(NodePtr* headR);
void insert_index(NodePtr head, int index);
void getUserInput(info* person);

void main(){
	NodePtr head = NULL;
	head = (NodePtr) malloc(sizeof(Node));
	
	// Checks if memory allocation is successful
	if (head == NULL){
		exit(1);
	}
	
	// Function calls
/*	insert_front(&head);
	insert_end(&head);
	insert_index(&head, 0);
*/	


	// Free memory
	free(head);

	
	exit(0);
}

// Function  Definitions

void insert_front(NodePtr* head){
	NodePtr new_node;
	new_node = (NodePtr) malloc(sizeof(Node));
	
	info person;
	getUserInput(&person);
	
	
	new_node->data = person;
	new_node->next = *head;
	
	*head = new_node;
	
	// Free new_node
	free(new_node);
}

void insert_end(NodePtr* headR){
	NodePtr new_node;
	new_node = (NodePtr) malloc(sizeof(Node));
	
	info person;
	getUserInput(&person);
	
	new_node->data = person;
	new_node->next = NULL;
	
	for(;*headR != NULL; headR = &(*headR)->next);
	*headR = new_node;
	
	
	// Free new_node
	free(new_node);
	/*Node *current = head;
	
	info person;
	getUserInput(&person);
	
	for(;current->next != NULL; current = current->next);
	current->next = (NodePtr) malloc(sizeof(Node));
	current->next->data = person;
	current->next->next = NULL;*/
}

void insert_index(NodePtr head, int index){
	NodePtr current = head;
	NodePtr new_node;
	new_node = (NodePtr) malloc(sizeof(Node));
	
	int i;
	for(i = 0; i != index; current = current->next, i++){
		if (current == NULL && i < index || i != index){
			printf("\nIndex out of bounds!\n");
			return;
		}
	}
	
	info person;
	getUserInput(&person);
	
	new_node->data = person;
	new_node->next = current;
	current = new_node;
	
	
	// Free new_node
	free(new_node);
}

void getUserInput(info* person){
	getchar(); // Eats Enter or New Line 
	printf("Enter Full Name : ");
	fgets(person->name,sizeof(person->name), stdin);
	person.name[strcspn(person->name, "\n")] = '\0'; // Remove trailing newline
	
}


