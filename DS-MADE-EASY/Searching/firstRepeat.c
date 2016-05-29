#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Searching
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/ 

void printFirstRepeat(int arr[], int n)
{
	int count[n];
	memset(count, 0, sizeof(count));
	int i;
	for(i=0; i<n; i++)
	{
		if(count[arr[i]]>0)
			count[arr[i]] = -count[arr[i]];
		else
			count[arr[i]] = -i;
		
	
	}
	for(i=0; i<n; i++)
	{
		if(count[arr[i]]<0)
		{ printf("%d\n",arr[i]);
			return;}
	}
	
	
	
}

int main()
{
	
	int arr[] =  {3,2,1,2,2,3};
	printFirstRepeat(arr, sizeof(arr)/sizeof(arr[0]));
	
	
	
}