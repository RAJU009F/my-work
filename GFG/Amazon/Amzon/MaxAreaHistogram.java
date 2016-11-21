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
# Problem Statement	:  Max area in Histogram
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/


class MaxAreaHistogram
{

	public  int maxArea(int input[])
	{
		int n =  input.length;
		Stack<Integer> s =  new Stack<Integer>();
		int area = 0;
		int maxArea = 0;
		
		int top ;
		int i;
		for(i=0; i<n;)
		{
			if(s.isEmpty() || input[i]>=input[s.peek()])
			{s.push(i);
				i++;}
			else
			{
				top  =  s.peek();
				s.pop();
				if(s.isEmpty())
						area = input[top]*i;
				else
						area = input[top]*(i-s.peek()-1);
					
				maxArea = maxArea>area?maxArea:area;				
				
			}
			}
			while(!s.isEmpty())
			{
				
				top  =  s.peek();
				s.pop();
				if(s.isEmpty())
						area = input[top]*i;
				else
						area = input[top]*(i-s.peek()-1);
					
				maxArea = maxArea>area?maxArea:area;				
				
				
				
				
			}
			
		
		return maxArea;
		
		
		
		
	}
	public static void main(String args[])
		{
			int arr [] = {1,2,3,4,5,6,1,0,7};
			int arr1 [] = {1,2,2,1};
			MaxAreaHistogram h =  new MaxAreaHistogram();
			
			System.out.println(h.maxArea(arr));
			System.out.println(h.maxArea(arr1));
		
		}

}