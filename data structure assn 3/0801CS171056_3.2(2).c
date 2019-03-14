struct queue
{
   int data;
   struct listItem *next;	
};

typedef struct queue QUEUE;

//create a new node
QUEUE *createQueue()
{
	QUEUE *create;
	create = (QUEUE*)malloc(sizeof(QUEUE));
	create->next=NULL;
	return create;
}

QUEUE *insert_at_end(QUEUE *front,QUEUE *rear,int num)
{
	QUEUE *makenode,*temp;
	temp = front;
	makenode = createQueue();
	makenode->data = num;
	if(front==NULL)
	{
		front = makenode;
		rear = makenode;
	}
	else
	{
	    while(temp->next!=NULL)
	    temp=temp->next;
		temp->next = makenode;
		rear= makenode;    
    }
    return front; 
}
//function to insert an element
QUEUE *enqueue(QUEUE *front,QUEUE *rear,int num)
{
	front=insert_at_end(front,rear,num);
	return front;
}
//function to delete an element
QUEUE *dequeue(QUEUE *front)
{
	if(front==NULL)
	{
		printf("UNDERFLOW");
		return;
	}
	else
	{
		QUEUE *temp=front;
		front=front->next;
		free(temp);
		return front;
	}
}
//returns the topmost element
int peek(QUEUE *front)
{
	if(front==NULL)
	{
		printf("UNDERFLOW");
		return;
	}
	else
		return front->data;
}
//prints the queue
void printQueue(QUEUE *front)
{
	if(front==NULL)
	{
		printf("UNDERFLOW");
		return;
	}
	else
	{
		QUEUE *temp=front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
