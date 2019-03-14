#include<stdio.h>
#include<stdlib.h>
struct listItem
{
	int item;
	struct listItem *next;
};

typedef struct listItem NODE;

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

NODE *deleteNode(NODE *start,int num)
{
	NODE *temp=start;
	NODE *delete1;
	if(start==NULL)
	{
	printf("list is empty");
	return start;
    }
    if(start->item==num) //deletion of first node
	{ 
    delete1=start->next;
    start=start->next;
    free(delete1);
    return start;
    }
    while(temp->next!=NULL) //deletion in between or at the end
    {
    	if(temp->next->item==num)
    	{
    		delete1=temp->next;
    		temp->next=delete1->next;
    		free(delete1);
    		return start;
		}
		temp=temp->next;
	}
	printf("element %d not found",num);
    
}

NODE *printList(NODE *head)
{
	NODE *temp=head;
	while(temp!=NULL)
	{
	printf("%d\n",temp->item);
	temp=temp->next;
    }
}

