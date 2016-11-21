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
# Problem Statement	: 0/1 Knapsack Problem
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Knapsack01
{
	public  static int knapsack(int v[], int wt[] , int W, int N)
	{
		int[][]   K= new int[N+1][W+1];
		
		for(int i=0; i<=N; i++)
		{
			
			for(int w=0; w<=W; w++)
			{
				if(w==0||i==0)
						K[i][w] = 0;
				else if(w>=wt[i-1])
				{
					K[i][w] = Math.max(v[i-1]+K[i-1][w-wt[i-1]] , K[i-1][w] );
				}else
					K[i][w] = K[i-1][w] ;
				
				
			}
			
			
		}
		
		return K[N][W];
		
	}
	

	public static void main(String args[])
		{
			int v[] = {60, 100, 120};
			int w[] = {10, 20, 30};
			int W  = 50;
		    int N =  v.length;
			
			System.out.println(knapsack(v, w, W, N));
		
		}

}