#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Medians
# Problem Statement	: find min and max in an array
# Description		: 
# Complexity		: O(n/2)
=======================
#sample output
----------------------

=======================
*/

void findMinMax(int arr[], int n)
{
	int i,j;
	int min = INT_MAX;
	int max = INT_MIN;
	
	for(i=0; i<=n-2; i+=2)
	{
		if(arr[i]>arr[i+1])
		{
			
			if(arr[i]>max)
				max = arr[i];
			if(arr[i+1]<min)
				min =  arr[i+1];
		}else
		{
			if(arr[i]<min)
				min = arr[i];
			if(arr[i+1]>max)
				max =  arr[i+1];	
		}	
	}
	
	printf("Min:: [%d]\n",min);
	printf("Max:: [%d]\n",max);
	
	
}

int main()
{
	
	int arr[] = {12,10,5,15,18,12,4,16};
	
	findMinMax(arr, sizeof(arr)/sizeof(arr[0]));
	
}
