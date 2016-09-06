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

class LIS
{
	
	public static  void lis(int arr[], int len)
	{
		int[] L = new int[len];
		
		for(int i=0; i<len; i++)
			L[i] = 1;
		for(int i=1; i<len; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(arr[i]>arr[j] && L[i]<L[j]+1)
					L[i] = L[j]+1;
				
			}
			
		}
		int max = L[0];
		for(int i=1; i<len; i++)
			if(max<L[i])
				max = L[i];
	System.out.println(max);
		
		
	}
	
	public static void main(String args[])
	{
		
		int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
		lis(arr, arr.length);
		
		
	}
}