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
# Problem Statement	: Sub Array with given sum
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class SumSubArray
{
	
	public static void findSubArray(int arr[],  int n, int sum)
	{
		int start =0 ;
		int cur_sum = arr[0];
		for(int i=0; i<n; i++)
		{
			while(cur_sum>sum && start<i-1)
			{
				cur_sum -=arr[start];
				start--;
			}
			
			if(cur_sum==sum)
			{System.out.println("Array present between"+start+" and "+i);
			return;}
			
			if(cur_sum<sum)
				cur_sum +=arr[i];
			
		}
		
		
	}
	
	public static void main(String args[])
	{
		int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
		
		findSubArray(arr, arr.length, 23);
		
		
	}
	
	
}