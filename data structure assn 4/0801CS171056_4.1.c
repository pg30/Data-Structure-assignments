#include<stdlib.h>
#include<stdio.h>
#include"tree.h"
void inorder_range(NODE *root,int x,int y)
{
	if(root!=NULL)
	{
		inorder_range(root->left,x,y);
		if(x<=root->data && root->data<=y)
		printf("%d\n",root->data);
		inorder_range(root->right,x,y);
	}
}
int main()
{
	NODE *root = NULL; 
	root = insert(root,10);
	root = insert(root,8);
	root = insert(root,12);
	root = insert(root,6);
	root = insert(root,9);
	root = insert(root,7);
	root = insert(root,11);
	root = insert(root,13);
	inorder_range(root,8,12);
}
