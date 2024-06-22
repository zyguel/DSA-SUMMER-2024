/*
	AUTHOR: ZYGUEL PHILIP E. CABOGOY
	DSA-SUMMER 2024
	DATE CODE COMPLETED: JUNE 22, 2024
	ACT_07_SETS_ARRAY
*/
#include <stdio.h>
#include <stdlib.h>
#include "set_array.h"
int main(int argc, char *argv[]) {
	
	
	int n_sets = 0;
	int n_elem = 0;
	printf(" WELCOME! THIS PROGRAM IS ABOUT THE ARRAY IMPLEMENTATION OF SETS\n"
			"This Program is a slight variation of the activity  it is where it accepts \"n\" sets"
		   "\n\nEnter number of sets: ");
	scanf(" %d", &n_sets);
	// I did this so that the extra 2 sets are where the intersection and union results are set
	// **sets is a double pointer because I am creating an array of pointers to structure Set 
	Set **sets = initSetsArray(n_sets + 2); // this function returns an array of Pointers
	
	int i = 0;
	int j = 0;
	int temp_elem = 0;
	while(i < n_sets){
		
		printf(" \n\nEnter number of elements for Set [%d] : ", i);
		scanf(" %d", &n_elem);
		sets[i] = createSet(n_elem);
		while(j < n_elem){
			 temp_elem = 0;
			 printf("SET[%d] : Element[%d] : ", i, j);
			 if(scanf(" %d", &temp_elem)){
			 	addElement(sets[i], temp_elem);
			 	j++;
			 }else{
			 	printf("Invalid Number!\n\n");
			 	getchar();
			 	continue;
			 }
		}
		j = 0;
		n_elem = 0; // Making sure it stays 0 after each loop
		i++;
	}
	// Find Intersection
	int intersectionSize = 0;
	
	int *intersection = findIntersection(sets, n_sets, &intersectionSize);
	printf("Intersection size: %d\n", intersectionSize);
	if (intersectionSize > 0) {
	    printf("Intersection elements: ");
	    for (int i = 0; i < intersectionSize; i++) {
	        printf("%d ", intersection[i]);
	    }
	    printf("\n");
	} else {
	    printf("No common elements found in all sets.\n");
	}
	
	// Find Union
	int unionSize = 0;
	int *unionSet = findUnion(sets, n_sets, &unionSize);
	
	if (unionSet != NULL) {
	    printf("Union size: %d\n", unionSize);
	    printf("Union elements: ");
	    for (int i = 0; i < unionSize; i++) {
	        printf("%d ", unionSet[i]);
	    }
	    printf("\n");
	
	    // Don't forget to free the union array when you're done with it
	    free(unionSet);
	} else {
	    printf("Failed to find union or union is empty.\n");
	}
	// Please Disregard since this is just to check if memory is allocated and if data is well stored
	printf("\n1st Set capacity check : %d\n",sets[0]->capacity);
	printf("\nLast Set capacity check : %d\n",sets[n_sets - 1]->capacity);	
	
	i = 0;
	
	free(intersection);
	free(unionSet);
	free(sets);
    exit(1);
}
