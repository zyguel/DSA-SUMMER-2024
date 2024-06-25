#ifndef CLOSEDHASH_H
#define CLOSEDHASH_H

typedef struct {
	char *product; // This as key
	double price; 
}Prod, *ProdPtr;


typedef struct {
	Prod **table;
	int size;
	int capacity;
}ProdHashTable;

void initHashTable(ProdHashTable *pht);
int hashFunction(char *key, int capacity);
void insertProd(ProdHashTable *pht, ProdPtr p);
void resizePHT(ProdHashTable *pht);
ProdPtr findProdPrice(ProdHashTable *pht, char *key);
void deleteProd(ProdHashTable *pht, char *key);
void visualizePHT(ProdHashTable *pht);
int isFull(ProdHashTable *pht);
int isEmpty(ProdHashTable *pht);
#endif