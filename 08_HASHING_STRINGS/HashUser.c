#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashUser.h"

void initHashTable(UsrHashTable* hashTable) {
    hashTable->size = 0;
    hashTable->capacity = 10;
    hashTable->threshold = 6;
    hashTable->table = (UsrNode **)malloc(hashTable->capacity * sizeof(UsrNode *));
    for (int i = 0; i < hashTable->capacity; i++) {
        hashTable->table[i] = NULL;
    }
}

int hashFunction(char *name, int capacity) {
    int hash = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hash = (hash * 31 + name[i]) % capacity;
    }
    return hash;
}

void resizeHashTable(UsrHashTable *hashTable) {
    int oldCapacity = hashTable->capacity;
    hashTable->capacity *= 2;
    hashTable->threshold = (int)(hashTable->capacity * 0.65);
    UsrNode **newTable = (UsrNode **)malloc(hashTable->capacity * sizeof(UsrNode *));
    for (int i = 0; i < hashTable->capacity; i++) {
        newTable[i] = NULL;
    }

    for (int i = 0; i < oldCapacity; i++) {
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
