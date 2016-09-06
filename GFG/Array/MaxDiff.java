import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Array
# Problem Statement	: MaxDiff between two elements
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class MaxDiff

{
	public static void findmaxDiff( int arr[], int n)
	{
		int min = arr[0];
		int maxdiff = arr[1] -arr[0];
		for(int i=1; i<n; i++)
		{
			if(arr[i]-min>maxdiff)
					maxdiff = arr[i] - min;
			if(min>arr[i])
					min = arr[i];
			
		}
		
		System.out.println("max diff"+maxdiff);
	}
	
	public static void main(String args[])
	{
		
		int arr[] = {2, 3, 10, 6, 4, 8, 1};
		
		findmaxDiff(arr, arr.length);
		
		
		
	}
	
	
	
}