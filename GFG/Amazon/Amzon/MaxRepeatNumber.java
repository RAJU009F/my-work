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
# Problem Statement	: max repeat number
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class  MaxRepeatNumber
	{
		public static int maxRepeatnum(int arr[], int K)
		{
			
			for(int i=0; i<arr.length; i++)
			{
				
				arr[arr[i]%K] += K;
				
				
			}
			
			int max = arr[0];
			int res = 0;
			
			
			// to get the min element incase of clash of more repeated numbers 
			for(int i=0; i<arr.length; i++)
					arr[i] =  arr[i] - arr[i]%K;
			
			for(int i=1; i<arr.length; i++)
			{
				
				System.out.print(arr[i]+" ");
				if(arr[i]>max)
				{
					max = arr[i];
					res = i;
				}
				
			}
			
			return res;
		}
		
		public static void main(String args[])
			{
				
			int arr[] = {2, 3, 3, 5, 3, 4, 1, 7};
			int n = 8;
			int k = 8;
			int arr1[] = {2, 2, 1, 0, 0, 1};
			//System.out.println(maxRepeatnum(arr, 8));
			System.out.println("\n"+maxRepeatnum(arr1, 3));
			
			int arr2[] = {2, 2, 1, 2};
			//System.out.println(maxRepeatnum(arr2, 3));
			}
	
	
	}