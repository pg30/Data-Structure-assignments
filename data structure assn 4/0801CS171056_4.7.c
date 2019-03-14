#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

NODE *tree(int inorder[],int postorder[],int start,int end,int *index)
{
    if (start>end)
        return NULL;

    NODE *newNode = getNode(postorder[*index]);
    (*index)--;
    if (start==end)
        return newNode;
    int iIndex = search(inorder,start,end,newNode->data);
    newNode->right = tree(inorder,postorder,iIndex+1,end,index);
    newNode->left = tree(inorder,postorder,start,iIndex-1,index);
    return newNode;
}

NODE *createTree(int inorder[], int postorder[], int n)
{
    int index = n-1;
    return tree(inorder,postorder,0,n-1,&index);
}

int search(int arr[],int start,int end,int value)
{
    int i;
    for (i=start;i<=end;i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}

int main()
{
    int inorder[]   = {5,9,3,6,2,7,4,8};
    int postorder[] = {9,5,6,3,7,8,4,2};
    int n = sizeof(inorder)/sizeof(inorder[0]);
    NODE *root = createTree(inorder,postorder,n);
    preorder(root);
    return 0;
}
