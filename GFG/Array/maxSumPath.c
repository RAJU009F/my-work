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
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: min sub array with sum greater
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void maxSumPath(int arr1[], int m, int arr2[],  int n )
{
	int i=0;
	int j=0;
	int sum1 =0;
	int sum2 = 0;
	int result =0;
	
	while(i<m &&j<n)
	{
		
		if(arr1[i]<arr2[j])
			sum1 +=arr1[i++];
		else if(arr1[i]>arr2[j])
			sum2 +=arr2[j++];
		else
		{
			result +=sum1>sum2?sum1:sum2;
			
			sum1 = 0;
			sum2 = 0;
			
			while(i<m && j<n && arr1[i] == arr2[j])
			{
				result += arr1[i];
				i++;
				j++;
				
			}
			
		}
		
		
		
	}
	while(i<m)
		sum1 +=arr1[i++];
	while(j<n)
		sum2 +=arr2[j++];
	
	
	result +=sum1>sum2?sum1:sum2;
	
	printf("max sum : %d\n",result);
}

int main()
{
	int ar1[] = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] = {1, 5, 7, 8, 10, 15, 16, 19};
	maxSumPath(ar1, sizeof(ar1)/sizeof(ar1[0]), ar2, sizeof(ar2)/sizeof(ar2[0]));
}