#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Medians
# Problem Statement	: find the median of two arrays
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


int max(int a ,int b)
{
	return a>b?a:b;
	
}
int min(int a, int b)
{
	return a<b?a:b;
	
}
int findMedainUtil(int arr1[], int l1, int h1, int arr2[],  int l2, int h2 )
{
	
	int m1  =  l1+(h1-l1)/2;
	int m2 	=  l2+(h2-l2)/2;
	if(arr1[m1] == arr2[m2])
		return arr1[m1];
	if((h1-l1+h2-l2)<4)
		return (max(arr1[l1], arr2[l2])+min(arr1[h1], arr2[h2]))/2;
	else if(arr1[m1]>arr2[m2])
	{
		return findMedainUtil(arr1, l1, m1, arr2, m2, h2 );
	}else
	{
		return findMedainUtil(arr1, m1, h1, arr2, l2, m2 );
		
	}
		
	
	
	
}

int findMedain(int arr1[], int arr2[], int n)
{
	
	return findMedainUtil(arr1, 0,  n-1, arr2, 0, n-1);
	
}


int main()
{
	
	int arr1[] = {1, 12, 17, 26, 38,40,67};
	int arr2[] = {2, 13, 17, 30, 45,46, 89};
	printf("Median is %d \n",findMedain(arr1, arr2, sizeof(arr1)/sizeof(arr2[0])));
	
	
}