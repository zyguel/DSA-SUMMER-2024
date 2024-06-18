#include <stdio.h>
#include <stdlib.h>
#include "CircularQ.h"



int main (int argc, char *argv[]){
	circularQ *cq = create_cQ(); 
	enque(cq, 5);
	enque(cq, 10);
	enque(cq, 15);
	enque(cq, 20);
	
	display(cq);
	deque(cq);
	display(cq);
}



