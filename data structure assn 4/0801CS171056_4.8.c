#include<stdio.h>
#include<stdlib.h>
void swap(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void heapify(int heap[], int n, int i)
{
    int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 
    if (left<n && heap[left]>heap[largest])
        largest = left;
    if (right<n && heap[right]>heap[largest])
        largest = right;
    if (largest!=i)
    {
        swap(heap[i],heap[largest]);
        heapify(heap,n,largest);
    }
}
 
void heapSort(int heap[],int n)
{
    int i;
	for (i=n/2-1;i>=0;i--)
        heapify(heap,n,i);
    int j;
	for (j=n-1;j>=0;j--)
    {
        swap(heap[0],heap[j]);
        heapify(heap,j,0);
    }
}
 
void print(int heap[],int n)
{
    int i;
	for (i=0;i<n;++i)
        printf("%d ",heap[i]);
}
 
int main()
{
    int heap[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(heap)/sizeof(heap[0]);
    heapSort(heap, n);
    print(heap, n);
}
