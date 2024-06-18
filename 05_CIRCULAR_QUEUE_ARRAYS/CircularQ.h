#ifndef CIRCULAR_Q
#define CIRCULAR_Q
#define MAX 10
typedef struct {
	int data[MAX];
	int front ;
	int rear;
	
}circularQ;


circularQ* create_cQ();
void enque(circularQ *cq, int data); // insert rear (0(1))
void deque(circularQ *cq); // Delete Front (0(1))
int front(circularQ cq);
int rear(circularQ cq);
int isEmpty(circularQ cq);

int isFull(circularQ cq);

void display(circularQ *cq); 
#endif