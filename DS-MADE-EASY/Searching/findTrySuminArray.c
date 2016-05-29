#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Searching
# Problem Statement	: sum of two elemnts ;
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/ 
void swap(int *a,  int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
	
	
}
void heapiFy(int arr[], int i, int n)
{
	int largest = i;
	int l = i*2+1;
	int r = i*2+2;
	
	if(l<n && arr[largest]<arr[l])
			largest = l;
	if(r<n && arr[largest]<arr[r])
			largest = r;
		
	if(i!=largest)
	{
		swap(&arr[i], &arr[largest]);
		heapiFy(arr,largest,n);
		
	}
	
	
}

void sort(int arr[],  int n)
{
	int i;
	for(i=n/2-1; i>=0; i--)
		heapiFy(arr,i,n);
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0], &arr[i]);
		heapiFy(arr, 0,i);
	}
	
	
	
}

void findTry(int arr[], int n, int data)
{
	sort(arr, n);
	int i, j, k;
	for(i=0; i<n-2; i++)
	{
		j=i+1;
		k = n-1;
		while(j<k)
		{
			if(arr[i] + arr[j] + arr[k] == data)
			{
				printf("%d, %d, %d",arr[i] , arr[j] , arr[k]);
				return;
			}else if(arr[i] + arr[j] + arr[k] >data)
			{
				k--;
			}else
				j++;
		}
				
	}
	
	
	
	
}


int main()
{
	
	int arr[]   = {45,32,54,12,89,40,50};
	
	findTry(arr, sizeof(arr)/sizeof(arr[0]),98);
	return 0;
}