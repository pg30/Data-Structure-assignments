#include<stdio.h>
#include"tree.h"
int longestPath(NODE *root)
{
	if(root==NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	
	int lp = longestPath(root->left);
	int rp = longestPath(root->right);
	
	return max(lh+rh+1,max(lp,rp)); 
}
