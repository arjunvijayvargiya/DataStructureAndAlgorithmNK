#include<stdio.h>
#include<stdlib.h>
struct heap{
	int *array;
	int count;
	int capacity;
};
heap *createHeap(int n)
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->capacity=n;
	h->array=(int *)malloc(sizeof(int)*h->capacity);
	h->count=0;
	return h;
}
int left(heap *h,int i)
{
    int left=2*i+1;
	if(left>=h->count)
        return -1;
	else
	    return left;	
}
int right(heap *heap,int i)
{
	int right=2*i+2;
	if(right>=h->count)
	   return -1;
	else
	   return right;
}
int parent(heap *h,int i)
{
	int parent=(i-1)/2;
	if(parent<0)
	  return -1;
	else
	  return parent;
}
void percolatedown(heap *h,int i)
{
	int left=left(h,i);
	int right=right(h,i);
	int max;
	if(left!=-1 && h->array[i]<h->array[left])
	  max=left;
	else
	  max=i;
	if(right!=-1 && h->array[max]<h->array[right])
	  max=right;
	if(max!=i)
	{
		//swap
		int temp=h->array[i];
		h->array[i]=h->h->array[max];
		h->array[max]=temp;
	}
	percolatedown(h,max);
}
int deletemax(heap *h)
{
	if(h->count==0)
	  return -1;
	int temp=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	percolatedown(h,0);
	return temp;
}
void insert(heap *h,int k)
{
	h->count++;
	h->array[h->count-1]=k;
	int i=h->count-1;
	while(i>=0 && k>h->array[parent(h,i)])
	{//swap # percolate up
		int temp=h->array[i];
		h->array[i]=h->array[parent(h,i)];
		h->array[parent(h,i)]=temp;
		i=parent(h,i);
	}
}
void buildheap(heap *h,int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		h->array[i]=arr[i];
	}
	h->count=n;
	for(i=(n-1)/2;i>=0;i--)
	{
		percolatedown(h,i);
	}
}
int main()
{
	
	return 0;
}
