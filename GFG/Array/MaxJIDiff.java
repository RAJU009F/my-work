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
# Problem Statement	: max j-i
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class MaxJIDiff
{
	
	public static void maxDiff(int arr[], int n)
	{
		int[]  L = new int[n];
		int[]  R= new int[n];
		L[0]=arr[0];
		for(int i=1; i<n; i++)
		{
			if(L[i-1]<arr[i])
				L[i] = L[i-1];
			else
				L[i] = arr[i];
			
		}	

		R[n-1] = arr[n-1];
		for(int i=n-2; i>=0; i--)
		{
			if(R[i+1]>arr[i])
				R[i] = R[i+1];
			else
				R[i] = arr[i];
			
		}
		
		int i=0;
		int j=0;
		int maxdiff= -1;
		while(i<n && j<n)
		{
			if(L[i]<R[j])
			{j++;
			maxdiff = maxdiff>j-i?maxdiff:j-i;}
			else
			{
				i++;
			}
		}
		
		
		System.out.println(maxdiff);
	}
	
	
	public static void main(String args[])
	{
		int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
		
		maxDiff(arr, arr.length);
		
	}
	
	
	
}