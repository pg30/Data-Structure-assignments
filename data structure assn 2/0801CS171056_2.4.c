#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

NODE *mergeLinkedList(NODE *head1,NODE *head2)
{
	if(head1==NULL)
	return head2;
	if(head2==NULL)
	return head1;
	if(head1==NULL&&head2==NULL)
	{
		return;
	}
	NODE *temp=head1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head2;
	head1=sort(head1);
	return head1;
}

/*int main()
{
	int i,j;
	NODE *head=NULL,*head1=NULL;
	for(i=1;i<=10;i++)
	{
		head=insert_at_end(head,rand()%50);
	}
	for(j=1;j<=6;j++)
	{
		head1=insert_at_end(head1,rand()%10);
	}
	printList(head);
	printf("\n\n");
	printList(head1);
	printf("\n\n");
	head=mergeLinkedList(head,head1);
	printList(head);
	return 0;
	
}*/
