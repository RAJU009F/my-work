// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void merge(int arr1[], int m, int arr2[],  int n )
{
	int i;
	for( i=n-1; i>=0; i--)
	{
		int j ;
		int last = arr1[m-1];
		for(j=m-2; j>=0&&arr1[j]>arr2[i]; j--)
			arr1[j+1] = arr1[j];
		
		if(j!=m-2)
		{
			arr1[j+1] = arr2[i];
			arr2[i] = last;
			
		}
		
		
		
		
	}
	
	
	
}
	
	void printArray(int arr[],  int n)
	{
		int i;
		
		for(i=0; i<n; i++)
		{
			printf("%d ", arr[i]);
			
		}
			printf("\n");
		
	}
	
	
int main()
{
	int arr1[] = {1, 5, 9, 10, 15, 20};
	int arr2[] = {2, 3, 8, 13};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);
	printf("before\n");
	printArray(arr1, m );
	printArray(arr2, n);

	merge(arr1, m, arr2, n );
	printf("after\n");
	printArray(arr1, m );
	printArray(arr2, n);

	
}