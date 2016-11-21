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
# Topic or Type 	: GFG/Amazon
# Problem Statement	: Fill numbers
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class FillNumbers
	{
		public static boolean printFilledNumbersUtil(int  arr[], int N, int cur)
		{
				if(cur==0)
						return true;
			
				for(int  i=0; i<2*N-cur-1; i++)
				{
					if(arr[i] == 0  && arr[cur+i+1]==0)
					{
						arr[i]=arr[cur+i+1]= cur;
						if(printFilledNumbersUtil(arr, N, cur-1))
								return true;
						arr[i]=arr[cur+i+1]= 0;
						//return false;
					}
					
					
					
					
				}
				return false;
			
		}
	
		public static void printFilledNumbers(int N)
			{
			
				int[]  arr =  new int[2*N];
				printFilledNumbersUtil(arr, N, N);
				
				for(int i=0; i<2*N; i++)
						System.out.print(arr[i]+" ");
				
			}
	
	
	
		public static void main(String args[])
			{
				printFilledNumbers(7);
							System.out.println(" ");
				printFilledNumbers(207);
				System.out.println(" ");
				printFilledNumbers(8);
				System.out.println(" ");
				printFilledNumbers(9);
				System.out.println(" ");
				printFilledNumbers(19);
			
			
			}
	
	
	}