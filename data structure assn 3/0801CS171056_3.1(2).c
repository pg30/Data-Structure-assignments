struct stack
{
   int data;
   struct listItem *next;	
};
typedef struct stack STACK;
//create a new node
STACK *createStack()
{
	STACK *create;
	create = (STACK*)malloc(sizeof(STACK));
	create->next=NULL;
	return create;
}

//insertion at beginning
STACK *insert_at_beg(STACK *top,int num)
{
	STACK *makenode;
	makenode = createStack();
	makenode->data = num;
	if(top == NULL)
	{
		top=makenode;
	}
	else
	{
		makenode->next = top;
		top = makenode;
	}
	return top;
}
STACK *push(STACK *top,int num)
{
	top = insert_at_beg(top,num);
	return top;
}

STACK *pop(STACK *top)
{
	if(top==NULL)
	return;
	else
	{
		STACK *temp = top;
		top = top->next;
		free(temp);
		
	}
	return top;
}

int peek(STACK *top)
{
	if(top==NULL)
	return;
	else
	return top->data;
}

void printStack(STACK *top)
{
	STACK *temp=top;
	while(temp!=NULL)
	{
	printf("%d\n",temp->data);
	temp=temp->next;
    }
}
