#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
int levelSum(NODE *root)
{
	if(root==NULL)
		return 0;
	int sum =root->data;
	 return sum;
}
int maxLevelSum(NODE *root,int level)
{
	
}
int main()
{
	NODE *root = NULL; int i;
	root = insert(root,10);
	root = insert(root,8);
	root = insert(root,12);
	root = insert(root,6);
	root = insert(root,9);
	root = insert(root,7);
	root = insert(root,11);
	root = insert(root,13);
	int result = levelSum(root);
	printf("%d",result);
}

