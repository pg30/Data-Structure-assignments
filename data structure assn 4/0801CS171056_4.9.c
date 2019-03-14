#include<stdio.h>
#include<stdlib.h>
void swap(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void maxHeap(int heap[],int i,int n)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if (left<n && heap[left]>heap[i])
        largest = left;
    if (right<n && heap[right]>heap[largest])
        largest = right;
    if (largest!=i)
    {
        swap(heap[i],heap[largest]);
        maxHeap(heap,largest,n);
    }
}

void convert(int heap[],int n)
{
    int i;
	for (i = (n-2)/2; i >= 0; --i)
        maxHeap(heap, i, n);
}

void print(int *heap,int size)
{
    int i;
	for (i = 0; i < size; ++i)
        printf("%d ", heap[i]);
}
 
int main()
{
    int heap[] = {4,6,10,7,9,21,11,13,19};
    int n = sizeof(heap)/sizeof(heap[0]);
    convert(heap, n);
    print(heap, n);
    return 0;
}
