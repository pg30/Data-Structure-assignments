#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct node *next;
};

typedef struct stack STACK;

STACK *createStack()
{
	STACK *create;
	create = (STACK*)malloc(sizeof(STACK));
	create->next=NULL;
	return create;
}

struct queue
{
    STACK *s1;
    STACK *s2;
};

typedef struct queue QUEUE;

void enqueue(QUEUE *q, int num)
{
    push(&q->s1, num);
}

void dequeue(QUEUE *q)
{
    //int num;
    if (q->s1 == NULL && q->s2 == NULL) {
        printf("UNDERFLOW");
        return;
    }
    if (q->s2 == NULL) {
        while (q->s1 != NULL) {
        num = pop(&q->s1);
        push(&q->s2, num);
        }
    }
    num = pop(&q->s2);
   // printf("%d\n", num);
}

void push(STACK **top, int data)
{
    STACK *newnode = createStack();
    if(top==NULL)
		(*top) = newnode;
	else
	{
    	newnode->data = data;
    	newnode->next = (*top);
    	(*top) = newnode;
    }
}

int pop(STACK **top)
{
    int res;
    STACK *temp;
    if (*top == NULL) {
        printf("UNDERFLOW \n");
        return;
    }
    else {
        temp = *top;
        res = temp->data;
        *top = temp->next;
        free(temp);
        return res;
    }
}

void display(STACK *top1,STACK *top2)
{
    while (top1 != NULL) {
        printf("%d\n", top1->data);
        top1 = top1->next;
    }
    while (top2 != NULL) {
        printf("%d\n", top2->data);
        top2 = top2->next;
    }
}

int main()
{
	QUEUE *q1 = (QUEUE*)malloc(sizeof(QUEUE));
	q1->s1=NULL;
	q1->s2=NULL;
	int i;
	for(i=0;i<10;i++)
		enqueue(q1,i);
	dequeue(q1);
	display(q1->s1,q1->s2);
}
