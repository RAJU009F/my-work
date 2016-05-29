#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Searching
# Problem Statement	: verify if there exist a triods with A[i]^2 + A[j]^2 = A[k]^2;
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

void findTry(int arr[], int n)
{
	sort(arr, n);
	int i;
	for(i=0; i<n; i++)
		arr[i] = arr[i]*arr[i];
	
	for(i=0; i<n; i++)
	{
		int K = arr[i];
		int l = 0;
		int h = n-1;
		while(l<h)
		{
			if(arr[l]+arr[h] == K)
			{printf("Try exists [ %d + %d = %d] \n",arr[l], arr[h] , K);
			return;}
			else if(arr[l]+arr[h]>K)
					h--;
			else
					l++;
			
			
			
		}
		
	}
	
	printf("sddsd\n");
	
}


int main()
{
	
	int arr[] = {1,5,2,3,4,6};
	findTry(arr, sizeof(arr)/sizeof(arr[0]));
	
	
	
	
}