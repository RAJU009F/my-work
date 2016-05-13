#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: Heap sort
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	 *b = t;
	
}
void heapiFy(int a[], int size, int i)
{
	int largest  =  i;
	int l =  2*i+1;
	int r  =  2*i+2;

	if(l<size && a[l]>a[largest])
			largest = l;
	if(r<size && a[r]>a[largest])
			largest = r;
	
	if(i!=largest)
	{
		swap(&a[i], &a[largest]);
		heapiFy(a, size, largest);
		
	}
	
}

void heapSort(int a[], int n)
{
	int i;
	for(i=n/2-1; i>=0;i--)
		heapiFy(a, n ,i);
	
	for(i=n-1; i>=0 ;i--)
	{
		swap(&a[i], &a[0]);
		
		heapiFy(a, i, 0);
	}
	
}
void printArray(int a[], int n)
{
	int i;
	for(i=0 ;i<n; i++)
			printf("[%d]\t", a[i]);
	printf("\n");	
	
}

//int DeleteKthLargest(int )

int main()
	{
			
	int arr[] = {2,5,1,7,4,3,6,8};
	printArray(arr, sizeof(arr)/sizeof(arr[0]) );
	heapSort(arr, sizeof(arr)/sizeof(arr[0]));
	printArray(arr, sizeof(arr)/sizeof(arr[0]) );
	
	
	return 0;
	}