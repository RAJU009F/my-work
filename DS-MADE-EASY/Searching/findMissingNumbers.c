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

void findrepeatNumbers(int arr[], int n)
{
	int i, X=0;int  Y=0;
	int XOR = arr[0];
	for(i=1; i<n; i++)
		XOR ^=arr[i];
	for(i=1; i<=n-2; i++)
		XOR ^=i;
	
	int right_most_bit = XOR & ~(XOR-1);
	
	for(i=0; i<n; i++)
		if(arr[i] & right_most_bit)
				X=X ^arr[i];
		else
				Y=Y ^arr[i];
	for(i=1; i<=n-2; i++)
			if(i & right_most_bit)
					X=X ^i;
			else
					Y=Y ^i;
	printf("X=%d, Y=%d",X, Y);
}

int main()
	{
		int arr[] = {1,2,3,4,5,6,6,5};
		
		findrepeatNumbers(arr, sizeof(arr)/sizeof(arr[0]));
	
	
	
	}