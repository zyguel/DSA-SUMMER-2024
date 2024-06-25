#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClosedHash.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ProdHashTable pht;
	initHashTable(&pht);
	deleteProd(&pht, "key"); // Should return a printf Statement;
	
	ProdPtr p = (Prod *)malloc(sizeof(Prod));
	p->price = 5560.50;
	p->product = (char *)malloc(250 * sizeof(char));
	strcpy(p->product,"Intel i7-12700H");
	insertProd(&pht,p);
	/*char *prod2find = (char *)malloc(250 * sizeof(char));
	strcpy(prod2find,"Intel i7-12700H");*/
	ProdPtr pfound = findProdPrice(&pht,"Intel i7-12700H");
	if (pfound != NULL){
		printf("Product Found!\n");
		printf("Product name: %s\n", pfound->product);
		printf("Product Price %.2lf\n", pfound->price);
	}
	visualizePHT(&pht);
	deleteProd(&pht, "Intel i7-12700H");
	deleteProd(&pht, "Intel i7-12700H"); // deletion not success cause its empty
	
	
	return 0;
}