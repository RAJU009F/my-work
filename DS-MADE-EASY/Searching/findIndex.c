#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Searching
# Problem Statement	: find the index of the elemnt in a rotated array ;
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/ 

int findIndexUtil(int arr[], int l, int r, int key )
{
	if(l>r)
			return -1;
	int m = l+(r-l)/2;
	if(arr[m] == key)
			return m;
	if(arr[l]<=arr[m])
	{
		if(arr[l]<=key && arr[m]>key)
			return findIndexUtil(arr, l, m-1, key);
		else	
			return findIndexUtil(arr, m+1, r, key);
		
	}else
	{
		if(arr[r]>=key && arr[m]<key)
			return findIndexUtil(arr, m+1, r, key);
		else	
			return findIndexUtil(arr, l, m-1, key);
		
	}
		
	
	
	
	
}

void findIndex(int arr[],  int n, int key)
{
	printf("Index of Key=%d is :: %d", key, findIndexUtil(arr, 0, n-1, key));
	
	
}

int main()
{
	
	int arr[] = {6,7,8,9,10,11,1,2,3,4,5};
	findIndex(arr, sizeof(arr)/sizeof(arr[0]),80);
	
	return 0;
}