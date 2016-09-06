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

class SortedArrays
	{
		public static void printArray(int arr[],  int n)
		{
			for(int i=0; i<n; i++)
			{
				System.out.print(arr[i]+" ");
			}
			System.out.println();
		}
		
		public static void printSortedArraysUtil(int a[],  int i, int m,  int b[],  int j,  int n,  int c[], int len, boolean f)
		{
			if(f)
			{
				if(len>0)
					printArray(c, len+1);
				for(int k=i; k<m; k++)
				{
					if(len==0)
					{
						c[len] = a[k];
						
						printSortedArraysUtil(a, k+1, m, b, j, n ,c, len, !f);
						
					}else
					{
						if(a[k]>c[len])
						{
							c[len+1] = a[k];
							printSortedArraysUtil(a, k+1, m, b,j,n, c, len+1,!f );
						}
						
					}
					
				}
				
				
			}else
			{
				for(int l=j; l<n; l++)
				{
					if(b[l]>c[len])
					{
						c[ len+1 ] = b[l];
						printSortedArraysUtil(a,i, m, b, l+1, n, c, len+1, !f);
					}
					
					
				}
				
				
			}
			
			
			
		}
		
		public static void printSortedArrays(int a[],  int m ,int b[],  int n)
		{
			
			int[] c = new int[(m+n)];
			
			printSortedArraysUtil(a, 0, m, b, 0, n, c, 0, true);
			
			
		}
		public static void main(String args[])
		{
			int a[] = {10, 15, 25};
			int b[] = {5, 20, 30};

		printSortedArrays(a, a.length, b, b.length);
			
		}
		
		
		
	}