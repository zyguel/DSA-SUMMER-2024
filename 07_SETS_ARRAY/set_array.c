#include <stdio.h>
#include <stdlib.h>
#include "set_array.h"

// Function to initialize an array of Set pointers
Set **initSetsArray(int n_sets) {
    Set **sets = (Set **)malloc(n_sets * sizeof(Set *));
    if (sets == NULL) {
        fprintf(stderr, "Memory allocation failed for sets array.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < n_sets; ++i) {
        sets[i] = NULL; // Initialize each pointer to NULL
    }
    
    return sets;
}

// Helper function to resize the Set
void resizeSet(Set *set, int newCapacity) {
    set->capacity = newCapacity;
    set->elements = realloc(set->elements, sizeof(int) * newCapacity);
}

// Create a new set with given capacity
Set* createSet(int capacity) {
    Set *newSet = malloc(sizeof(Set));
    newSet->size = 0;
    newSet->capacity = capacity;
    newSet->elements = calloc(capacity, sizeof(int));
    return newSet;
}

// Add an element to the set : : EXTRA FUNCTION
void addElement(Set *set, int element) {
	// Note: this function is designed to delete from 1 set at a time!!!
    if (set->size == set->capacity) {
        resizeSet(set, set->capacity * 2); // Double the capacity
    }
    set->elements[set->size++] = element;
}

// Deletion : EXTRA FUNCTION
int deleteElement(Set *set, int element) {
    // Note: this function is designed to delete from 1 set at a time!!!
	
	int index = -1;
    for (int i = 0; i < set->size; ++i) {
        if (set->elements[i] == element) {
            index = i;
            break;
        }
    }
    if (index!= -1) {
        for (int i = index; i < set->size - 1; ++i) {
            set->elements[i] = set->elements[i + 1];
        }
        --(set->size);
        return 1;
    }
    return 0;
}

int* findIntersection(Set **sets, int n_sets, int *intersectionSize) {
    if (n_sets == 0 || sets == NULL) {
        *intersectionSize = 0;
        return NULL;
    }

    // Start with the first set's capacity as the initial size
    int *intersection =(int*) malloc(sets[0]->capacity * sizeof(int));
    if (intersection == NULL) {
        *intersectionSize = 0;
        return NULL;
    }
    
    int intersectionCount = 0;

    // Check each element of the first set
    for (int i = 0; i < sets[0]->size; i++) {
        int element = sets[0]->elements[i];
        int inAllSets = 1;  // Assume the element is in all sets

        // Check if this element is in all other sets
        for (int j = 1; j < n_sets; j++) {
            if (!containsElement(sets[j], element)) {
                inAllSets = 0;
                break;
            }
        }

        // If the element is in all sets, add it to the intersection
        if (inAllSets) {
            intersection[intersectionCount++] = element;
        }
    }

    // Resize the intersection array to the actual size
    int *resizedIntersection = realloc(intersection, intersectionCount * sizeof(int));
    if (resizedIntersection == NULL && intersectionCount > 0) {
        free(intersection);
        *intersectionSize = 0;
        return NULL;
    }

    *intersectionSize = intersectionCount;
    return resizedIntersection ? resizedIntersection : intersection;
}

int* findUnion(Set **sets, int n_sets, int *unionSize) {
    if (n_sets == 0 || sets == NULL) {
        *unionSize = 0;
        return NULL;
    }

    // Calculate the maximum possible size of the union
    int maxUnionSize = 0;
    for (int i = 0; i < n_sets; i++) {
        maxUnionSize += sets[i]->size;
    }

    // Allocate memory for the union
    int *unionSet = (int*) malloc(maxUnionSize * sizeof(int));
    if (unionSet == NULL) {
        *unionSize = 0;
        return NULL;
    }

    int unionCount = 0;

    // Function to check if an element is already in the union
    int containsElement(int *arr, int size, int element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) return 1;
        }
        return 0;
    }

    // Add elements from all sets to the union
    for (int i = 0; i < n_sets; i++) {
        for (int j = 0; j < sets[i]->size; j++) {
            int element = sets[i]->elements[j];
            if (!containsElement(unionSet, unionCount, element)) {
                unionSet[unionCount++] = element;
            }
        }
    }

    // Resize the union array to the actual size
    int *resizedUnion = realloc(unionSet, unionCount * sizeof(int));
    if (resizedUnion == NULL && unionCount > 0) {
        free(unionSet);
        *unionSize = 0;
        return NULL;
    }

    *unionSize = unionCount;
    return resizedUnion ? resizedUnion : unionSet;
}

int containsElement(Set *set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1;  // Element found
        }
    }
    return 0;  // Element not found
}
