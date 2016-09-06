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
# Problem Statement	: min Gap between two numbers
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class MinGap
{

	public static void findMinGap(int arr[],  int len, int a,  int b)
	{
		int prev=-1;
		int mind = Integer.MAX_VALUE;
		int i;
		for(i=0; i<len; i++)
		{
			if(arr[i]==a || arr[i]==b)
			{
				prev = i;
				break;
			}
		}
		
		i++;
		for(; i<len; i++)
		{
			if(arr[i]==a || arr[i]==b)
			{
				if(arr[i]!=arr[prev] && ((i-prev)<mind) )
				{mind = i - prev;
					prev = i;}
				else
					prev = i;
			}
			
		}
		
		System.out.println(mind);
		
	}

	public static void main(String args[])
	{
		int arr[] = {3, 5, 4, 2, 6, 9, 0, 0, 5, 4, 8, 3};
		
		findMinGap(arr, arr.length, 3, 6);
		
	}



}