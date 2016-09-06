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
# Problem Statement	: max profit from share price
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class ReArrangeNums
{
	public static void printArray(int arr[],  int n)
	{
		for(int i=0; i<n; i++)
			System.out.print(arr[i]+" ");
		
	}
	
	public static void reArrange(int arr[], int n)
	{
		int i=-1;
		for(int j=0; j<n; j++)
		{
			if(arr[j]<0)
			{
				i++;
				arr[i] ^=arr[j];
				arr[j] ^=arr[i];
				arr[i] ^=arr[j];
				
			}
		}
		
		int pos = i+1;
		int neg = 0;
		
		while(pos<n && neg<pos && arr[neg]<0)
		{
			arr[pos] ^=arr[neg];
			arr[neg] ^=arr[pos];
			arr[pos] ^=arr[neg];
			pos++;
			neg +=2;
		}
		
		
	}
	
	public static void main(String args[])
	{
		int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
		printArray(arr, arr.length);
		reArrange(arr, arr.length);
		printArray(arr, arr.length);
	}
	
}

