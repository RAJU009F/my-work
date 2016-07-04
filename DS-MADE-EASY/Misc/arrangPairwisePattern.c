#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Misc
# Problem Statement	: find median two sorted arrays
# Description		: solutuins 1. mergeing and counting , 2. modified binary search , 3. index =  index of median of array1, index2 = (m+n)/2-1; 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void reverse(char *arr, int l, int r)
{
	while(l<r)
	{
		
		arr[l] ^=arr[r];
		arr[r] ^=arr[l];
		arr[l] ^=arr[r];
		l++;
		r--;
	}
	
	
}
void arrangePattern(char *arr, int n)
{
	
reverse(arr, 0, n/2-1);	
	
	int count=2;
	while(1)
	{
		int i=n/2-count;
		if(i>=0)
		{
		int j=i;
		char t = arr[j];
		while(count>=j-i)
		{
			arr[j] = arr[j+1];
			j++;
			
		}
		arr[j] = t;
			
		count = 2*count;	
			
			
		}else
			break;
		
		
		
	}
	
	
}

int main()
	{
		char arr[] = "aaaaabbbbb";
		printf("%s\n", arr);
		arrangePattern(arr, sizeof(arr)/sizeof(arr[0]));
		printf("%s",arr);
	}