import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: circular Sub Array  sum
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class CircularSumSubArray
{
	public static int kadane(int arr[],  int n)
	{
		int max = arr[0];
		int cur  =  arr[0];
		int i;
		for( i=1; i<n; i++)
		{
			cur = (cur+arr[i]) > arr[i]?(cur+arr[i]) :arr[i];
			max = max>cur?max:cur;
			
			
		}
		
		return max;
	}
	
	public static int  circularSumArray(int arr[],  int n)
	{
		int max_kadane = kadane(arr, n);
		int max_wrap = 0;
		int i;
		for(i=0; i<n; i++)
		{
			max_wrap += arr[i];
			arr[i] = -arr[i];
			
		}
		
		max_wrap = max_wrap+kadane(arr, n);
		
	
		return max_kadane>max_wrap?max_kadane:max_wrap;
	}
	
	public static void main(String args[])
	{
		int arr[] = {11, 10, -20, 5, -3, -5, 8, -13, 10};

		System.out.println("max Circular sum: "+circularSumArray(arr, arr.length));	
		
	}
	
	
	
}