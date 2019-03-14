#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
	struct TreeNode *left;
	int data;
	struct TreeNode *right;
};
typedef struct TreeNode NODE;

NODE *getNode(int data)
{
	NODE *makenode;
	makenode = (NODE*)malloc(sizeof(NODE));
	makenode->left=NULL;
	makenode->right=NULL;
	makenode->data=data;
	return makenode;
}

bool contains(NODE *root,int i)
{
	int result;
	if(root==NULL)
		return false;
	else if(i<root->data)
		result = contains(root->left,i);
	else if(i>root->data)
		result = contains(root->right,i);
	else 
		return true;
}

NODE *insert(NODE *root,int data)
{
	NODE *makenode = getNode(data);
	if(root==NULL)
		root = makenode;
	else if(data<root->data)
		root->left = insert(root->left,data);
	else 
		root->right = insert(root->right,data);
	return root;
}
NODE *findSmallestNode(NODE *root)
{
	if(root==NULL||root->left==NULL)
		return root;
	else return findSmallestNode(root->left);
}

NODE *findLargestNode(NODE *root)
{
	if(root==NULL||root->right==NULL)
		return root;
	else return findLargestNode(root->right);
}

NODE *deleteNode(NODE *root,int i)
{
	if(root==NULL)
		printf("value not found");
	else if(i > root->data)
		deleteNode(root->right,i);
	else if(i < root->data)
		deleteNode(root->left,i);
	else if(root->left&&root->right)
	{
		NODE *temp = findLargestNode(root->left);
		root->data = temp->data;
		deleteNode(root->left,temp->data);
	}
	else
	{
		NODE *temp=root;
		if(root->left==NULL&&root->right==NULL)
			root=NULL;
		else if(root->left==NULL)
			root=root->left;
		else if(root->right==NULL)
			root=root->right;
		free(temp);
	}
}

int min(NODE *root)
{
	if(root==NULL)
		return -1;
	if(root->left==NULL)
		return root->data;
	else
		return min(root->left);
}

int max(NODE *root)
{
	if(root==NULL)
		return -1;
	if(root->right==NULL)
		return root->data;
	else
		return max(root->right);
}

int isComplete(NODE *root,int count,int index)
{
	if(root==NULL)
		return 1;
	if(index>=count)
		return 0;
	return(iscomplete(root->left,count,2*index+1)&&iscomplete(root->right,count,2*index+2))
}

int totalNodes(NODE *root)
{
	if(root==NULL)
		return 0;
	else
		return totalNodes(root->left)+totalNodes(root->right)+1;
}

void toIntArray(NODE *root,int r[])
{
	if(root!=NULL)
	{
		static int i=0;
		toIntArray(root->left,r);
		r[i]=root->data;
		i++;
		toIntArray(root->right,r);
	}
}
void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
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
	//inorder(root);
	//int result = min(root);
	//printf("%d",result);
    //int r[100];
	//toIntArray(root,r);
	//for(i=0;i<sizeof(r);i++)
	//{
	//	printf("%d  ",r[i]);
	//}
	int count = totalNodes(root);

	
}
