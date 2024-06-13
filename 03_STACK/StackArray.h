#ifndef STACK_ARRAY
#define STACK_ARRAY


#define MAX 20

typedef struct {
	int data[MAX];
	int top; // used to be int count if it was not stack
}SAL; // SAL(STACK ARRAY LIST)

void initStack(SAL *s);

bool stack_pop(SAL *s);
bool stack_push(SAL *s, int elem);
bool isEmpty(SAL s);
bool isFull(SAL s);
int stack_peek(SAL *s);
void display(SAL s);
void visualize(SAL s);

#endif
 
