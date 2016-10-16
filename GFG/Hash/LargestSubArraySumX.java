import java.io.*;
import java.lang.*;
import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Hash
# Problem Statement	: find the largest sub array which forms the sum 0
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class LargestSubArraySumX

{
		public static  void lergestsubArraywithSumKWithHash(int arr[], int X)
		{
			int sum = 0;
			
			HashMap<Integer, Integer> hm =  new HashMap<Integer, Integer>();
			
			int max_len = 0;
			for(int i=0; i<arr.length; i++)
			{
				sum +=arr[i];
				
				if(arr[i]==0 && max_len==0);
					{
						max_len =1;
						
					
					}
				
				if(sum==0)
					max_len = i+1;
				
				Integer prev_i =  hm.get(sum);
			
				if(prev_i !=null)
				{
					max_len = max_len<(i-prev_i+1)?(i-prev_i+1):max_len;
					
				}
				else
					hm.put(sum, i);
					
				
				
			}
			
			
			System.out.println("Max len :"+max_len);
			
			
		}
	
		public static  void lergestsubArraywithSumKWithoutHash(int arr[], int X)
		{
			
			int cur_sum  =arr[0];
			int start =0;
			int max_len = 0;
			boolean found = false;
			for(int i=1 ;i <arr.length; i++)
			{
				
				while(cur_sum>X && start<i-1)
				{
					cur_sum = cur_sum-arr[start];
					start++;
				}
			
				if(cur_sum == X)
				{
					max_len =  max_len > i-start?max_len:i-start;
					found = true;		
				}
				
				cur_sum = cur_sum+arr[i];
				
			}
				
			if(found)		
				System.out.println("max len "+max_len);
			else
				System.out.println(X+" Does not exists");
		}
	
	
		public static void main(String args[])
		{
			int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
			
			
			//lergestsubArraywithSumKWithoutHash(arr, 0);
			lergestsubArraywithSumKWithoutHash(arr, 10);
			//lergestsubArraywithSumKWithHash(arr, 0);
			lergestsubArraywithSumKWithHash(arr, 10);
			
		}
	
	
}