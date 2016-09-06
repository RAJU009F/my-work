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

class SubSequence3
{
	public static void printSubSequence3(int arr[],  int n)
	{
		int[] left =  new int[n];
		int[] right =  new int[n];
		int min=0;
		int max=n-1;
		left[0] = -1;
		right[n-1] = -1;
		
		for(int i=1; i<n; i++)
			if(arr[min]<arr[i])
				left[i] = arr[min];
			else
			{left[i] = -1;
			min =i;}
			
		for(int j=n-2; j>=0; j--)
			if(arr[j]<arr[max])
				right[j] = arr[max];
			else
			{right[j] = -1;
				max = j;}
			
		for(int i=0; i<n; i++)
				if(left[i]!=-1 && right[i]!=-1)
					System.out.println("Sub sequence of 3: "+left[i]+" "+arr[i]+" "+right[i]);
			
		
	}
	
	public static void main(String args[])
	{
		int arr[] = {12, 11, 10, 5, 6, 2, 30};
		
		printSubSequence3(arr, arr.length);
		//return 0;
	}


}