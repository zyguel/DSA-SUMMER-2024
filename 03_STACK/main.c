#include <stdio.h>
#include "StackArray.h"

#ifdef _WIN32
    // Windows-specific code
    #define CLEAR_SCREEN "cls"
#else
    // POSIX-compliant code
    #define CLEAR_SCREEN "clear"
#endif
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {

	message();
	printf("\nPress Enter to Proceed!\n");
	getchar();
	system(CLEAR_SCREEN);
	SAL s;
	initStack(&s);
	stack_push(&s,5);
	stack_push(&s,10);
	stack_push(&s,15);
	stack_push(&s,20);
	stack_push(&s,25);
	stack_push(&s,30);

	
	printf("\nTOP IS %d\n", stack_peek(&s));
	stack_pop(&s);
	// 30 is removed 25 is shown
	printf("\nTOP IS %d\n", stack_peek(&s));
	visualize(&s);
	display(&s);
	return 0;
	
}
