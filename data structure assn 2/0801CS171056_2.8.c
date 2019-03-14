#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

NODE *pair_swap(NODE *head)
{
    if(head==NULL||head->next==NULL)
        return;
    NODE *prev,*curr;
    prev=head;
    curr=head->next;
    head=head->next;
    while(1)
    {
        NODE *temp=curr->next;
        curr->next=prev;
        if(temp==NULL||temp->next==NULL)
        {
          prev->next=temp;
          break;
        }
        prev->next=temp->next;
        prev=temp;
        curr=temp->next;
    }
    return head;
}

NODE *remove_alternate_node(NODE *head)
{
	NODE *temp=head;
	if(head==NULL||head->next==NULL)
	return head;
	while(1)
	{
		NODE *delete1;
		if(temp->next==NULL)
		break;
		delete1=temp->next;
		if(delete1->next==NULL)
		{
			temp->next=NULL;
			free(delete1);
	    }
	    else{
		temp->next=delete1->next;
		free(delete1);
		temp=temp->next;
	    }
	}
	return head;
	
}

NODE *insert_alternate(NODE *head1,NODE *head2)
{
     NODE *temp1 = head1, *temp2 = head2;
     NODE *next1, *next2;
 
     while (temp1!=NULL && temp2!=NULL)
     {
         next1 = temp1->next;
         next2 = temp2->next;
 
         temp2->next = next1;  
         temp1->next = temp2;  
 
         
         temp1 = next1;
         temp2 = next2;
    }
 
    head2=temp2; 
    return head1;
}

/*int main()
{
    NODE *head1=NULL,*head2=NULL;
    int i;
    for(i=0;i<4;i++)
    {
    	head1 = insert_at_end(head1,rand()%50);
    	head2 = insert_at_end(head2,rand()%50);
    }
    printList(head1);
    printf("\n");
    printList(head2);
    printf("\n");
    head1=insert_alternate(head1,head2);
    printList(head1);
}*/
