#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/DP
# Problem Statement	: find the product of two elements in an arry is equals to a given number 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void printPairProduct(int arr[], int n, int K)
{
	bool H[K];
	
	memset(H, 0, sizeof(H));
	
	
	int i;
	
	for(i=0;i<n;i++)
	{
		if(K%arr[i]==0 && H[K/arr[i]])
		{
		printf(" pair [(%d * %d)= %d] exists\n", arr[i], K/arr[i], K);
		return;
		}else
			H[arr[i]] = 1;
		
		
		
	}
	
	
	
	
	
}

int main()
{
	int arr[] = {10,30,34,90,40};
	
	printPairProduct(arr, sizeof(arr)/sizeof(arr[0]), 300);
	
	
}
