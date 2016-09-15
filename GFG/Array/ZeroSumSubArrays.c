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
// #include<map>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: List all Zero sum sub arrays
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void zeroSumSubArrays(int arr[],  int n)
{
	int start = 0;
	int cur_sum = arr[0];
	int i;
	for( i=1; i<n; i++)
	{
		while(cur_sum>0&&start<i-1)
		{
			cur_sum = cur_sum-arr[start];
			start++;
		}
		if(cur_sum==0)
			printf("subArray with sum zero: exists in range %d and %d\n", start, i);	
		
		cur_sum = cur_sum+arr[i];
	}
	
	 start = 0;
	 cur_sum = arr[0];
	for( i=0; i<n; i++)
	{
		while(cur_sum<0&&start>i+1)
		{
			cur_sum = cur_sum+arr[start];
			start--;
		}
		if(cur_sum==0)
			printf("subArray with sum zero: exists in range %d and %d\n", i,start);	
		
		cur_sum = cur_sum+arr[i];
	}
	
	
	 start = 0;
	 cur_sum = arr[0];
	for( i=1; i<n; i++)
	{	cur_sum +=arr[i];
		if(cur_sum==0)
			printf("subArray with sum zero: exists in range %d and %d", start, i);		
	}
	
	
	
	
	
	
}


int main()
{
	int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
	zeroSumSubArrays(arr, sizeof(arr)/sizeof(arr[0]));

}