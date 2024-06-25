#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashUser.h"

void initHashTable(UsrHashTable* hashTable) {
    hashTable->size = 0;
    hashTable->capacity = 10;
    hashTable->threshold = 6;
    hashTable->table = (UsrNode **)malloc(hashTable->capacity * sizeof(UsrNode *));
    int i; // Since for loop init declarations are allowed in C99 or C11
	for (i = 0; i < hashTable->capacity; i++) {
        hashTable->table[i] = NULL;
    }
}

int hashFunction(char *name, int capacity) {
    int hash = 0;
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        hash = (hash * 31 + name[i]) % capacity;
    }
    return hash;
}

void resizeHashTable(UsrHashTable *hashTable) {
    int oldCapacity = hashTable->capacity;
    hashTable->capacity *= 2;
    hashTable->threshold = (int)(hashTable->capacity * 0.65);
    UsrNode **newTable = (UsrNode **)malloc(hashTable->capacity * sizeof(UsrNode *));
    int i; // Since for loop init declarations are allowed in C99 or C11
    for (i = 0; i < hashTable->capacity; i++) {
        newTable[i] = NULL;
    }
    for (i = 0; i < oldCapacity; i++) {
        UsrNode *node = hashTable->table[i];
        while (node != NULL) {
            int newIndex = hashFunction(node->usr->name, hashTable->capacity);
            UsrNode *nextNode = node->link;
            node->link = newTable[newIndex];
            newTable[newIndex] = node;
            node = nextNode;
        }
    }

    free(hashTable->table);
    hashTable->table = newTable;
}

int isFull(UsrHashTable *hashTable) {
    return hashTable->size >= hashTable->threshold;
}

void insert(UsrHashTable *hashTable, UserPtr usr) {
    if (isFull(hashTable)) {
        printf("Current Hash Table is Full. Resizing Hash Table\n");
        resizeHashTable(hashTable);
    }

    int index = hashFunction(usr->name, hashTable->capacity);
    UsrNode *newNode = (UsrNode *)malloc(sizeof(UsrNode));
    newNode->usr = usr;
    newNode->link = NULL;

    UsrNode *current = hashTable->table[index];
    if (current == NULL) {
        hashTable->table[index] = newNode;
    } else {
        // Linear probing within the chain
        UsrNode *prev = NULL;
        while (current != NULL) {
            prev = current;
            current = current->link;
        }
        prev->link = newNode;
    }
    hashTable->size++;
}

UserPtr find(UsrHashTable *hashTable, char *name) {
    int index = hashFunction(name, hashTable->capacity);
    UsrNode *node = hashTable->table[index];
    while (node != NULL) {
        if (strcmp(node->usr->name, name) == 0) {
            return node->usr;
        }
        node = node->link;
    }
    return NULL;
}

void delete_usr(UsrHashTable *hashTable, char *name) {
    int index = hashFunction(name, hashTable->capacity);
    UsrNode *node = hashTable->table[index];
    UsrNode *prev = NULL;
    while (node != NULL) {
        if (strcmp(node->usr->name, name) == 0) {
            if (prev == NULL) {
                hashTable->table[index] = node->link;
            } else {
                prev->link = node->link;
            }
            free(node->usr->name);
            free(node->usr->address);
            free(node->usr);
            free(node);
            hashTable->size--;
            return;
        }
        prev = node;
        node = node->link;
    }
}

void visualize_hash(UsrHashTable *hashTable){
	printf("\t\t\t+-----------------------------------------------------+\n");
    printf("\t\t\t|             Hash  Table                             |\n");
    printf("\t\t\t|  Capacity = %d       Current size = %-6d          |\n", hashTable->capacity, hashTable->size);
    printf("\t\t\t|  Threshold = %d                                      |\n", hashTable->threshold);

	int i, j = 0; 
	if (hashTable->size > 0){
		for (i = 0; i < hashTable->capacity; i++){
			if(hashTable->table[i] != NULL){
			printf("\t\t\t|-----------------------------------------------------|\n");
			printf("\t\t\t| DATA [%d]:                                           \n", i);
			printf("\t\t\t|     INT Key: %d                                      \n",hashFunction(hashTable->table[i]->usr->name,hashTable->capacity));
			printf("\t\t\t|     String Key-->Name: %s                          \n",hashTable->table[i]->usr->name);
			printf("\t\t\t|     Address: %s                              \n",hashTable->table[i]->usr->address);
				if(hashTable->table[i]->link != NULL){
		
					UsrNode *current = hashTable->table[i];
					current = current->link; // Set to the next node as it is already displayed from the previous
					for(j = 1; current != NULL; current = current->link, j++){
						printf("\t\t\t|                                                     |\n");	
						printf("\t\t\t| Data[%d]->Node[%d]                                    \n", i, j);
						printf("\t\t\t|     INT Key: %d                                      \n",hashFunction(current->usr->name,hashTable->capacity));	
						printf("\t\t\t|     String Key-->Name: %s                          \n",current->usr->name);
						printf("\t\t\t|     Address: %s                                  \n",current->usr->address);
					}
					
				}
			}
		}
	}
   
    printf("\t\t\t+-----------------------------------------------------+\n");
    
    

}
