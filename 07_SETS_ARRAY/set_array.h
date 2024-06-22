#ifndef SET_ARRAY
#define SET_ARRAY

// Structure to represent a set
typedef struct {
    int *elements;
    int size; // Actual number of elements in the set
    int capacity; // Maximum capacity of the set
} Set;

// Function prototypes
Set **initSetsArray(int n_sets);
Set* createSet(int capacity);

void addElement(Set *set, int element);
int deleteElement(Set *set, int element);
int* findIntersection(Set **sets, int n_sets, int *intersectionSize);
int* findUnion(Set **sets, int n_sets, int *unionSize);


int containsElement(Set *set, int element);

#endif