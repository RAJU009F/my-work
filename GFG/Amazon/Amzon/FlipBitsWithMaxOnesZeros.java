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
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: FlipBits: 1. find max zeros  with one flip operation ,2. max ones with one flip opertion
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class FlipBitsWithMaxOnesZeros
	{
		public int max(int a, int b)
		{
			return a>b?a:b;
			
		}
	
		public  int max_ones(int arr[],  int n)
			{
				int total_ones = 0;
				int cur_max = 0;
				int max_diff = 0;
				
				for(int i=0; i<n; i++)
				{
					if(arr[i]==1)
							total_ones++;
						
					int val =  (arr[i]==1)?-1:1;

					cur_max = max(val, cur_max+val);
					max_diff = max(cur_max, max_diff);
					
					
					
				}
				
				max_diff =  max(0, max_diff);
				
				return max_diff+total_ones;
				
				
			
			}
			
		public int max_zeors(int arr[], int n)
			{
				int total_zeroes = 0;
				int cur_max = 0;
				int max_diff = 0;
				
				for(int i=0; i<n; i++)
				{
					if(arr[i]==0)
							total_zeroes++;
						
					int val =  (arr[i]==0)?-1:1;

					cur_max = max(val, cur_max+val);
					max_diff = max(cur_max, max_diff);
					
					
					
				}
				
				max_diff =  max(0, max_diff);
				
				return max_diff+total_zeroes;
			
			
			}
			
		public static void main(String args[])
			{
			
				FlipBitsWithMaxOnesZeros fp =  new FlipBitsWithMaxOnesZeros();
				int arr[] = {0, 1, 0, 0, 1, 1, 0};
				System.out.println("max noof ones: "+fp.max_ones(arr, arr.length));
				System.out.println("max noof zeors: "+fp.max_zeors(arr, arr.length));	
				
			
			
			}
	}