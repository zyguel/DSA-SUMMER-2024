#ifndef HASHUSER_H
#define HASHUSER_H

// User Attributes
typedef struct {
    char *name;
    char *address;
} User, *UserPtr;

// For Open Hashing; Separate Chaining
typedef struct node {
    UserPtr usr;
    struct node *link; // Pointer to the next node in the chain
} UsrNode;

// Hash Table with Linked List Data Structure
typedef struct {
    UsrNode **table; // Array of pointers to UsrNode
    int size; // Current number of nodes
    int threshold; // Data Limiter 
    int capacity;
} UsrHashTable;



void initHashTable(UsrHashTable* hashTable);
int hashFunction(char *name, int capacity);
void resizeHashTable(UsrHashTable *hashTable);
int isFull(UsrHashTable *hashTable);
void insert(UsrHashTable *hashTable, UserPtr usr);
UserPtr find(UsrHashTable *hashTable, char *name);
void delete_usr(UsrHashTable *hashTable, char *name);
void visualize_hash(UsrHashTable *hashTable);
#endif
