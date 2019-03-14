struct listItem
{
   int data;
   struct listItem *next;	
};

typedef struct listItem NODE;

//create a new node
NODE *getNode()
{
	NODE *create;
	create = (NODE*)malloc(sizeof(NODE));
	create->next=NULL;
	return create;
}

//insertion at beginning
NODE *insert_at_beg(NODE *head,int num)
{
	NODE *makenode;
	makenode = getNode();
	makenode->data = num;
	if(head == NULL)
	{
		head=makenode;
	}
	else
	{
		makenode->next = head;
		head = makenode;
	}
	return head;
}
//insert at the end
NODE *insert_at_end(NODE *head,int num)
{
	NODE *makenode,*temp;
	temp = head;
	makenode = getNode();
	makenode->data = num;
	if(head==NULL)
	head = makenode;
	else
	{
	    while(temp->next!=NULL)
	     temp=temp->next;
	
	temp->next = makenode;    
    }
    return head; 
}

//insert at a particular location
NODE *insert_at_location(NODE *head,int item,int num)
{
	NODE *makenode,*temp;
	temp = head;
	while(temp->next!=NULL)
	{
		if(temp->data==item)
		{
		makenode = getNode();
		makenode->data=num;
		makenode->next=temp->next;
		temp->next=makenode;
		break;
		}
		else
		temp=temp->next;
	}
}

// find a particular node
NODE *find_node(NODE *head,int item)
{
	NODE *temp;
	int count =0;
	temp=head;
	while(temp->next!=NULL)
	{
		count++;
		if(temp->data==item)
		{
		printf("item found at %d position",count);
		break;
		}
		temp=temp->next;
		
	}
}

// delete a node
NODE *deleteNode(NODE *head,int num)
{
	NODE *temp=head;
	NODE *delete1;
	if(head==NULL)
	{
	printf("list is empty");
	return head;
    }
    if(head->data==num) //deletion of first node
	{ 
    delete1=head->next;
    head=head->next;
    free(delete1);
    return head;
    }
    while(temp->next!=NULL) //deletion in between or at the end
    {
    	if(temp->next->data==num)
    	{
    		delete1=temp->next;
    		temp->next=delete1->next;
    		free(delete1);
    		return head;
		}
		temp=temp->next;
	}
	printf("element %d not found",num);
    
}
// printing a list
void printList(NODE *head)
{
	NODE *temp=head;
	while(temp!=NULL)
	{
	printf("%d\n",temp->data);
	temp=temp->next;
    }
}
// reversing a list
NODE *reverse(NODE *head)
{
	NODE *current,*prev,*next;
	current=head;
	prev=NULL;
	if(head==NULL)
	printf("empty list");
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return head;
}
// crete a copy of the list
NODE *copyList(NODE *head)
{
	NODE *head1=NULL,*previous=NULL,*temp1=head;
	while(temp1!=NULL)
	{
		NODE *temp = (NODE *)malloc(sizeof(NODE));
		temp->data=temp1->data;
		temp->next=NULL;
		if(head1==NULL)
		{
			head1=temp;
			previous=temp;
	    }
	    else
	    {
	    	previous->next=temp;
	    	previous=temp;
		}
		temp1=temp1->next;
	}
	return head1;
}
/* swap data field of linked list */
void swap(NODE *p1, NODE *p2)
{
	int temp = p1->data;
	p1->data = p2->data;
	p2->data = temp;
}
// sorting in ascending order
NODE *sort(NODE *head)
{
	NODE *start = head;
	NODE *traverse;
	NODE *min;
	
	while(start->next)
	{
		min = start;
		traverse = start->next;
		
		while(traverse)
		{
			/* Find minimum element from array */ 
			if( min->data > traverse->data )
			{
				min = traverse;
			}
			
			traverse = traverse->next;
		}
		swap(start,min);			// Put minimum element on starting location
		start = start->next;
	}
	return head;
} 
 
 
/*int main()
{
	NODE *head = NULL,*head1;
	//char str[]="abcde";
	int i;
	for(i=0;i<10;i++)
	{
		head=insert_at_end(head,i);
		//printList(head);
	}
	head1=copyList(head);
	head1=reverse(head1);
	printList(head);
	printList(head1);
	
}*/
 
