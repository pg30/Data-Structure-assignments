#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char opr1[50],opr2[50];
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

STACK *pop(STACK *top,char res[])
{
	if(top==NULL)
	return;
	else
	{
		STACK *temp = top;
		top = top->next;
		strcpy(res,temp->data);
		free(temp);
		return top;
	}
}

void printStack(STACK *top)
{
	STACK *temp=top;
	while(temp!=NULL)
	{
		fputs(temp->data,stdout);
		temp=temp->next;
    }
}

int char_type(char c)
{
	if(c == '+' || c == '–' || c == '*' || c == '/')
		return 1;
	else 
		return 0;
}

void prefix_to_infix(char s1[])
{
	STACK *top = NULL;
	int i,len = strlen(s1);
	for(i=len-1;i>=0;i--)
	{
		char temp2[6],temp1[2];
		temp1[0]=s1[i];
		switch(char_type(s1[i]))
		{
			case 0:
				top = push(top,temp1);
				break;
			case 1:
				top = pop(top,opr1);
				top = pop(top,opr2);
				temp2[0]='(';				
				strcat(temp2,opr1);				
				strcat(temp2,temp1);				
				strcat(temp2,opr2);				
				temp1[0]=')';				
				strcat(temp2,temp1);
				top = push(top,temp2);
				break;
		}
	}
	printStack(top);
}

int main()
{
	char prefix[100];
	gets(prefix);
	prefix_to_infix(prefix);
}
