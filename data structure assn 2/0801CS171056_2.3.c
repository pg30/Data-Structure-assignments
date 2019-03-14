#include<stdio.h>
#include<stdlib.h>
struct listItem
{
	char data;
	struct listItem *next;
};

typedef struct listItem NODE;

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
int compareList(NODE *head,NODE *head1)
{
	NODE *temp,*temp1;
	temp=head;
	temp=head1;
	while(temp&&temp1)
	{
		if(temp->data==temp1->data)
		{
		temp=temp->next;
		temp=temp1->next;
		}
		else
		return 0;
	}
	if(temp==NULL && temp1==NULL)
	return 1;
	else
	return 0;
}

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

int isLinkedListPalindrome(NODE *head)
{
	NODE *head1;
	head1=copyList(head);
	head1=reverse(head1);
	int result = compareList(head,head1);
	if(result==1)
	return 1;
	else
	return 0;
}
