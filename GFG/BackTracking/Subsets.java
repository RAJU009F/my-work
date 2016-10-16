import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Backtracking
# Problem Statement	: Subsets: print all the possible subsets of a given set
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class Subsets{
	
	public static void printSubset(int sol[])
	{
		System.out.print("( ");
		for(int i=0; i<sol.length; i++)
				if(sol[i] !=-1)
					System.out.print(sol[i]+" ");
				
		System.out.print(")");		
			System.out.println();	
		
		
	}
	
	public static void subsetsUtil(int arr[], int sol[], int i, int j, int n)
	{
		if(j>=n)
		{
			printSubset(sol);
			return ;
			
		}
		
		sol[i] = arr[j];
		
		subsetsUtil(arr, sol, i+1, j+1, n);
		sol[i] = -1;
		
		subsetsUtil(arr, sol, i+1, j+1, n);
		
	}
	
	public static  void subsets(int arr[])
	{
		int n = arr.length;
		
		int[] sol = new int[n];
		for(int i=0; i<n; i++)
			sol[i] = -1;
		
		subsetsUtil(arr, sol, 0, 0, n);
		
		
	}
	
	
	public static void main(String args[])
	{
		
	int arr[] = {1,2,3};

	subsets(arr);	
		
		
	}
	
}