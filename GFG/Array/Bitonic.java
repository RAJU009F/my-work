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
# Problem Statement	: Bitonic Search : max lenght
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Bitonic
{
	public static void maxLength(int arr[],  int n)
	{
		int[] inc = new int[n];
		int[] dec = new int[n];
		
		
		inc[0]= 1;
		dec[n-1]= 1;
		
		for(int i=1;i<n; i++)
			inc[i] = (arr[i]>arr[i-1])?inc[i-1]+1:1;
		for(int i=n-2; i>=0; i--)
			dec[i] = (arr[i]>arr[i+1])?dec[i+1]+1:1;
		int j=0;
		int max = dec[j]+inc[j]-1;
		for(int i=1; i<n ; i++)
		{
			if((dec[i]+inc[i]-1)>max)
				 max = dec[i]+inc[i]-1;
		}
		
		System.out.println(max);
		
		
	}
	
	public static void main(String args[])
	{
		int arr[] = {12, 4, 78, 90, 45, 23};
		
		maxLength(arr, arr.length);
		
		
	}
	
	
	
	
	
}