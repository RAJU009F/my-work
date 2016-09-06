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
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: min sub array with sum greater
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class ContiguousSubArray

{
	public static int largestArray(int arr[],  int n)
	{
		int max_len = 1;
		int mn, mx;
		for(int i=0; i<n-1; i++)
		{
			mn = arr[i];
			mx = arr[i];
			HashSet<Integer> set = new HashSet<Integer>();
			set.add(arr[i]);
			
			for(int j=i+1; j<n; j++)
			{
					if(set.contains(arr[j]))
						break;
					set.add(arr[j]);
					mn = mn>arr[j]?arr[j]:mn;
					mx = mx>arr[j]?mx:arr[j];
					//System.out.println("max "+mx+"min "+mn);
					if(mx-mn == j-i)
					{	max_len = max_len>(j-i+1)?max_len:(j-i+1);
						System.out.println(mx+" "+mn);
					}
					//System.out.println("i "+i+"j "+j);
						
			}
			set.clear();
			
			
		}
		
		return max_len;
		
	}
	
	public static void main(String args[])
	{
		int arr[] = {10, 12, 12, 10, 10, 11, 10};
		
		System.out.println(largestArray(arr, arr.length));
	}

}