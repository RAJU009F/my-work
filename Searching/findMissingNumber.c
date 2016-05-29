#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Searching
# Problem Statement	: find the missing number
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/ 

void findMissing(int arr[],  int n)
{
	int i, X=arr[0];
	for(i=1; i<n; i++)
	{
		X ^= arr[i];
	}
	for(i=1; i<=n+1; i++)
		X ^= i;
	printf("\n %d\n", X);
}

void findOddNum(int arr[], int n)
{
	int i;
	for(i=1; i<n; i++)
	{
		arr[i] ^=arr[i-1]; 
	}
	
	printf("\n%d\n",arr[n-1]);
	
}

int main()
{
	int arr[] = {1,2,4,6,3,7,8};
	
	findMissing(arr, sizeof(arr)/sizeof(arr[0]));
	int arr1[] = {1,2,3,3,2,1,3};
	
	findOddNum(arr1, sizeof(arr1)/sizeof(arr1[0]));
}