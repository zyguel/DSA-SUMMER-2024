#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClosedHash.h"

void initHashTable(ProdHashTable *pht){
	pht->capacity = 10; // Initial Capacity of 10 as instructed
	pht->size = 0;
	pht->table = (Prod **)malloc(pht->capacity * sizeof(Prod *));
	int i;
	for (i = 0; i < pht->capacity; i++){
		pht->table[i] = NULL;
	}
}
int hashFunction(char *key, int capacity){
	int hash = 0;
	int i;
	for (i = 0; key[i] != '\0'; i++) {
        hash = ((hash ^ i) * 31 + key[i] + 1 + (hash ^ i)) % capacity;
    }
    return hash;
}
void insertProd(ProdHashTable *pht, ProdPtr p){
	if (isFull(pht)){
		resizePHT(pht);
	}
	int index = hashFunction(p->product, pht->capacity);
	if(pht->table[index] == NULL){
		pht->table[index] = p;
		
	}else{
		while(pht->table[index] != NULL || pht->table[index]->price > 0){
			index = (index + 1) % pht->capacity;
		}
		pht->table[index] = p;
	}
	pht->size++;
}
void resizePHT(ProdHashTable *pht){
	int prev_capacity = pht->capacity;
	pht->capacity *= 2;
	Prod **newTable = (Prod **) malloc(pht->capacity * sizeof(Prod *));
	int i, new_index;
	for(i = 0; i < prev_capacity; i++){
		if(pht->table[i] != NULL){
			new_index = hashFunction(pht->table[i]->product,pht->capacity);
			newTable[new_index] = pht->table[i];
		}
	}
	free(pht->table);
	pht->table = newTable;
}
ProdPtr findProdPrice(ProdHashTable *pht, char *key){
	int index = hashFunction(key, pht->capacity);
	if(strcmp(pht->table[index]->product,key) == 0){
		return pht->table[index];
	}else {
		while(strcmp(pht->table[index]->product,key) != 0){
			index = (index + 1) % pht->capacity;
		}
		// Double Check if it finds a match
		if(strcmp(pht->table[index]->product,key) == 0){
			return pht->table[index];
		}
	}
	return NULL;
}

void deleteProd(ProdHashTable *pht, char *key){
	if (isEmpty(pht)){
		printf("\n\nInvalid Operation, Table is Empty!\n\n");
		return;
	}
	int index = hashFunction(key, pht->capacity);
	if(strcmp(pht->table[index]->product,key) == 0){
		pht->table[index] = NULL;
	}else {
		while(strcmp(pht->table[index]->product,key) != 0){
			index = (index + 1) % pht->capacity;
		}
		// Double Check if it finds a match
		if(strcmp(pht->table[index]->product,key) == 0){
			pht->table[index] = NULL;
		}
	}
	pht->size--;
}
void visualizePHT(ProdHashTable *pht){
	int i = 0;
	printf("\nCapacity: %d   SIZE: %d\n", pht->capacity, pht->size);
	for(; i < pht->capacity; i++){
		if(pht->table[i] != NULL){
			printf("\nIndex %d: Product = %s, Price = %.2lf\n", i, pht->table[i]->product, pht->table[i]->price);
		} else {
			printf("\nIndex %d: Empty\n", i);
		}
	}
}

int isFull(ProdHashTable *pht){
	return pht->size >= pht->capacity - 2;
	// if it is near 1.0 then it is Full
}
int isEmpty(ProdHashTable *pht){
	return pht->size <= 0;
}