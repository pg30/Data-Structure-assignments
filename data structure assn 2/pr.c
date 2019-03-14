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
	
}

int main()
{
    NODE *head=NULL;
    int i;
    for(i=0;i<5;i++)
    {
    	head = insert_at_end(head,i);
    }
    head = pair_swap(head);
    printList(head);
}
