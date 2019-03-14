#include <stdio.h>
#include <stdlib.h>

struct listItem {
    int data;
    struct listItem* next;
    struct listItem* prev;
};
typedef struct listItem NODE;

NODE *getNode()
{
	NODE *makenode;
	makenode = (NODE *)malloc(sizeof(NODE));
	makenode->next=NULL;
	makenode->prev=NULL;
	return makenode;
}

/*Insert Node after a given Node */
void insertAfter(NODE *head, int data)
{
    if (head == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
    NODE *new_node = getNode();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
/* Add npde at end */
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;


    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;

    return;
}


void printList(NODE *head)
{
	NODE *temp=head;
  while(temp!=NULL)
  {
   printf("%d ", temp->data);
   temp = temp->next;
  }
}


/* To delete a Node */
void deleteNode(NODE *head, struct Node *del)
{
    if(*head_ref == NULL || del == NULL)
        return;
    if(*head_ref == del)
        *head_ref = del->next;
    if(del->next  != NULL)
        del->next->prev = del->next;
    if(del->prev != NULL)
    del->prev->next = del->next;

    free(del);
    return;

}


int main()
{
    struct Node* head = NULL;
     append(&head, 6);
     push(&head, 7);
     push(&head, 1);
     append(&head, 4);
     insertAfter(head->next, 8);
     deleteNode(&head, head->next);

    printf("Created DLL is: ");
    printList(head);

    getchar();
    return 0;
}


























