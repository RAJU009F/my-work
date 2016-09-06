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

void minSubArray(int arr[],  int n, int X)
{
	int cur_sum = 0;
	int start=0, start_i, end_i, len=n+1;
	int i=0;
	while(i<n)
	{
		
		while(cur_sum<=X && i<n)
			cur_sum +=arr[i++];

		
		while(cur_sum>X && start<n)
		{
			if(len>i-start)
			{
				len = i-start;
				start_i = start;
				end_i = i;
			}
		cur_sum -=arr[start];
		start++;	
		}
		
		 
		
	}
	
 printf("len= %d start=%d end = %d\n", len, start_i, end_i);	
}

int main()
{
	int arr[] = {1, 10, 5, 2, 7};
	minSubArray(arr,  sizeof(arr)/sizeof(arr[0]), 9);
	
	  int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
	  	minSubArray(arr3,  sizeof(arr3)/sizeof(arr3[0]), 280);
	return 0;
}