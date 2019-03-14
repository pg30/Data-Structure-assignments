struct stack 
{
	int top ;
	int *stk;
};

typedef struct stack STACK;
STACK *createStack()
{
	STACK *newstack = (STACK *)malloc(sizeof(STACK));
	newstack->top=-1;
	newstack->stk = (int *)malloc(maxsize*sizeof(int));
	return newstack;
}

void push(STACK *s,int num)
{
	if(s->top==maxsize-1)
	{
		printf("OVERFLOW");
		return;
	}
	else
	{
		s->top=s->top+1;
		s->stk[s->top]=num;
	}
	return;
}

int pop(STACK *s)
{
	int value;
	if(s->top==-1)
	{
		printf("UNDERFLOW");
		return;
	}
	else
	{
		value = s->stk[s->top];
		s->top=s->top-1;
	}
	return value;
}

int peek(STACK *s)
{
	if(s->top==-1)
	return;
	else
	return s->stk[s->top];
}

void printStack(STACK *s)
{
	if(s->top==-1)
		return;
	else
	{
		int j;
		for(j=s->top;j>=0;j--)
		{
			printf("%d \n",s->stk[j]);
		}
	}
}

