#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Heap or Priority Queue
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

struct Heap
{
	int size;
	int count;
	int *a;
	
	
};

struct Heap *initializeH(int size)
{
	struct Heap *h = (struct Heap *)malloc(sizeof(struct Heap));
	
	if(!h)
			return NULL;
		
	h->size = size;
	h->count  = 0;
	h->a = (int *)malloc(sizeof(int) * h->size);
	
	return h;
}


int parent(struct Heap *h,int i)

{
		if(i<=0 || i>=h->count)
			return -1;
	return  (i-1)/2;
	
}

int LChild(struct Heap *h, int i)
{
	if(i<0 || i>=h->count)
		return -1;
	return 2*i+1;
}

int RChild(struct Heap *h, int i)
{
	if(i<0 || i>=h->count)
		return -1;
	return 2*i+2;	
	
}

int getMax(struct Heap *h)
{
	if(h->count==0)
			return -1;
		
	return h->a[0];
}

void swap(int *a, int *b)
{
	
	int temp = *a;
	*a = *b;
	*b = temp;
	
}

void heapiFy(struct Heap *h, int i)
{
	
	int largest =  i;
	int l =  LChild(h, i);
	int r =  RChild(h, i);
	
	if(l<h->count && h->a[l]>h->a[largest])
		largest = l;
	if(r<h->count && h->a[r]>h->a[largest])
		largest = r;
	if(i!=largest)
	{
		swap(&h->a[i], &h->a[largest]);
		heapiFy(h, largest);
		
	}
	
}

void insert(struct Heap *h, int data)
{
	if(h->count==h->size)
	{
		printf("\nHeap reched max size\n");
		return;
		
	}
	h->count++;
	int i = h->count-1;
	while(i>=0 &&data>h->a[(i-1)/2])
	{
		h->a[i]=h->a[(i-1)/2];
		i = (i-1)/2;
	}
	h->a[i] = data;
}


int main()
	{
			
	int arr[] = {2,5,1,7,4,3,6,8};
	struct Heap *H = initializeH(10);
	int i;
	for(i=0; i<8; i++)
	{
		insert(H, arr[i]);
	}
	
	for(i=7; i>=0; i--)
	{
		swap(&H->a[0], &H->a[i]);
		H->count--;
		heapiFy(H, 0);
	}
	
	for(i=0;i<8; i++)
	{
		printf("[%d]\t",H->a[i]);
	}
	
	return 0;
	}