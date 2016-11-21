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
# Problem Statement	: noof ways to reach N 1.  nof ways to reach nth stair case using 1 or 2 or  3 steps at ones
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class NoofHopsToReachN
{
	// use DP 
	public  static  int noofHops(int arr[], int N)
	{
		if(N<=2)
				return N;
			
		
		int[]  count = new int[N+1];
			count[0] =1;
			count[1] = 1;
			count[2] = 2;
		
		for(int i=3; i<=N; i++)
				count[i] = count[i-1]+count[i-2]+count[i-3];
		
		return count[N];
	}
	
	// use  Fibonacci approach
	public  static  int noofHopsFibo(int arr[], int N)
	{
		if(N<=2)
				return N;
		int a  = 1;
		int b = 2;	
		int c = 4;
	
		for(int i=4; i<=N; i++)
		{
			int t =  a+b+c;
			 a = b;
			 b= c;
			 c = t;
			
		}
		
		return c;
	}
	
	
	
	
	
	public static void main(String args[])
	{
		
		int input[] = {1,2,3};
	
		System.out.println(noofHops(input, 1));	
		System.out.println(noofHops(input, 2));	
		System.out.println(noofHops(input, 3));	
		System.out.println(noofHops(input, 4));	
		System.out.println(noofHops(input, 5));	
		System.out.println(noofHopsFibo(input, 5));	
		
		
		
	}
	
}