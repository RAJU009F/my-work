import java.lang.*;
import java.util.*;
import java.io.*;

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
// #include<queue>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: Kth element in spiral print
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/

class KthElementSpiralPrint
	{
		
		public static  int  kthElement(int arr[][], int k)
		{
			int m  =  arr.length;
			int n =  arr[0].length;
			int t= 0;
			int b = m-1;
			int r = n-1;
			int l  =0;
			
			int i=0;
			while(t <=b || l<=r)
			{
				
				if(k<=(n-i))
				{	return arr[t][k-1];}
				if(k<= (m+n-1-i))
						return arr[k-(m)][r];
				if(k<=(n+m-1+n-1-i))	
					return arr[b][r-(k-(m+n-1))];
				if(k<=(m+n-1+m-1+n-2-i))
					return arr[b-(k-(m+n-1+m-1))][l];
				
				l++; r--;
				b--; t++;
				n= n-2;
				m = m-2;
				k = k- (m+n-1+m-1+n-2-i);
				i = i+2;
			}
			
			return -1;
			
			
		}
		public static void main(String args[])
			{
				int arr[][] = {{1,2,3},
							{	4,5,6},
								{7,8,9}};
				
				
				// System.out.println(kthElement(arr, 1));
				// System.out.println(kthElement(arr, 2));
				// System.out.println(kthElement(arr, 3));
				 // System.out.println(kthElement(arr, 4));
				 // System.out.println(kthElement(arr, 5));
				 // System.out.println(kthElement(arr, 6));
				// System.out.println(kthElement(arr, 7));
				 // System.out.println(kthElement(arr, 8));
				 System.out.println(kthElement(arr, 9));
						
				
				
				
				
			
			}
	
	
	}
	
	