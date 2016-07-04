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

// Method-1 merge and counting

void 	findMedianUsingCount(int arr1[], int m, int arr2[], int n)
{
	
	int count = (m+n)/2;
	int i=0, j=0;
	int mid;
	while(count)
	{
		if(arr1[i]>arr2[j])
		{j++;
	mid = arr2[j];}
		else
		{i++;
	
		mid = arr1[i];
	}
		
		count--;
		
		
	}
	
	
	printf("Median is [%d]\n", mid);
	
}

int  findMedianUsingBinarySearchUtil(int arr1[], int l1, int r1, int arr2[], int l2, int r2)

{
		int m1 = l1+(r1-l1)/2;
		int m2 = l2+(r2-l2)/2;
		
		if(arr1[m1] == arr2[m2])
			return arr1[m1];
		if( r1-l1+r2-l2<3)
			return ((arr1[l1]>arr2[l2]?arr1[l1]:arr2[l2])+(arr1[r1]<arr2[r2]?arr1[r1]:arr2[r2]))/2;
		else if(arr1[m1]>arr2[m2])
			return findMedianUsingBinarySearchUtil(arr1, l1, m1, arr2, m2, r2);
		else
			return findMedianUsingBinarySearchUtil(arr1, m1, r1, arr2, l2, m2);
		
	
	
	
}

void findMedianUsingBinarySearch(int arr1[], int m, int arr2[], int n)

{
	
	
	int median = findMedianUsingBinarySearchUtil( arr1, 0, m, arr2, 0, n);
	printf("Median : [%d]\n", median);
	
}





int main()
{
	int arr1[] = {5, 8, 10, 20};
	int arr2[] = {900};
	findMedianUsingCount(arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/ sizeof(arr2[0]));
	findMedianUsingBinarySearch(arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/ sizeof(arr2[0]));
	
}