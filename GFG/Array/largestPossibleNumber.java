// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: circular Sub Array  sum
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class largestPossibleNumber
{
	public static void heapiFy(String str[], int i,  int size)
	{
		int i = max;
		int l =  2*i+1;
		int r =  2*i+2;
		String x = null;
		String y = null;
		if(l<size )
		{
			x =  str[max]+str[l];
			y =  str[l]+str[max];
			
			if(x.compareTo(y) >= 1)
			{
				max = l;
			}
				
		}
		
		
		
	}
	
	public static void sort(String str[],  int n)
	{
		
		for (int i=n/2-1; i>=0; i--)
		{
			heapiFy(str, i, n);
			
			
		}
		
		
		
	}
	
	public static void printlargestNum(String str[], int n)
	{
		
		sort(str, n);
		
	}
	
	
	public static void main(String args[])
	{
		String[] str = {"54", "546", "548", "60"};
		
		printlargestNum(str, str.length);
	}
	
}