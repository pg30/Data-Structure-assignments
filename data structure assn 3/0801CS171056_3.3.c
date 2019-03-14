#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
   char data[1000];
   struct listItem *next;	
};
typedef struct stack STACK;
//create a new node
STACK *createStack()
{
	STACK *create;
	create = (STACK*)malloc(sizeof(STACK));
	create->next=NULL;
	return create;
}

//insertion at beginning
STACK *insert_at_beg(STACK *top,char str[])
{
	STACK *makenode;
	makenode = createStack();
	strcpy(makenode->data,str);
	if(top == NULL)
	{
		top=makenode;
	}
	else
	{
		makenode->next = top;
		top = makenode;
	}
	return top;
}
STACK *push(STACK *top,char str[])
{
	top = insert_at_beg(top,str);
	return top;
}

STACK *pop(STACK *top)
{
	if(top==NULL)
	return;
	else
	{
		STACK *temp = top;
		top = top->next;
		fputs(temp->data,stdout);
		free(temp);
		return top;
	}
}

void reverseWordsOfSentence(char sentence[])
{
	STACK *top = NULL;
	char *s1;
	s1 = strtok(sentence," ");
	while(s1!=NULL)
	{
		top = push(top,s1);
		s1 = strtok(NULL," ");
	}
	while(top!=NULL)
	{
		top = pop(top);
		printf(" ");
	}
}

int main()
{
	char sentence[1000];
	gets(sentence);
	reverseWordsOfSentence(sentence);
	return 0;
}
