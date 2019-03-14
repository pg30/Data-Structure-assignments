#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

void Count(NODE *head,int num)
{
	int count=0;
	NODE *temp=head;
	if(temp==NULL)
	count=0;
	else
	{
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			count++;
		}
		temp=temp->next;
	}
    }
    
	printf("%d",count);
}

int main()
{
	NODE *head=NULL;
	int i;
	for(i=1;i<5;i++)
		head=insert_at_end(head,2);
	for(i=1;i<4;i++)
	    head=insert_at_end(head,4);
	
	Count(head,3);
}
