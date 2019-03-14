struct queue
{
	int rear,front;
	int *que;
};
typedef struct queue QUEUE;

//function to create a queue
QUEUE *createQueue()
{
	QUEUE *newqueue = (QUEUE *)malloc(sizeof(QUEUE));
	newqueue->rear=-1;
	newqueue->front=-1;
	newqueue->que=(int *)malloc(maxsize*sizeof(int));
	return newqueue;
}

//function to insert a element
void enqueue(QUEUE *q,int num)
{
	if(q->rear==maxsize-1)
	{
		printf("OVERFLOW");
		return;
	}
	else if(q->front==-1&&q->rear==-1)
		q->front=q->rear=0;
	else
		q->rear=q->rear+1;
	q->que[q->rear]=num;
}

//function to delete a element
int dequeue(QUEUE *q)
{
	int value;
	if(q->front==-1||q->front>q->rear)
	{
		printf("UNDERFLOW");
		return -1;
	}
	else
	{
		value=q->que[q->front];
		q->front=q->front+1;
		
		if(q->front>q->rear)
		q->front=q->rear=-1;
		
		return value;
	}
}

int peek(QUEUE *q)
{
	if(q->front==-1||q->front>q->rear)
	{
		printf("UNDERFLOW");
		return -1;
	}
	else
		return q->que[q->front];
}

//function to print a queue
void printQueue(QUEUE *q)
{
	int i;
	if((q->front==-1)||(q->front>q->rear))
		printf("UNDERFLOW");
	else
	{
		for(i=q->front;i<=q->rear;i++)
		printf("%d	",q->que[i]);
	}
	
}
