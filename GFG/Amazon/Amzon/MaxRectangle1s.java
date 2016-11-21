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
# Problem Statement	:  Max rectanle of 1s in boolean matrix
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/


class MaxRectangle1s
{
	
	public int maxAreaUtil(int input[])
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
	
	public  int maxRect(int arr[][])
	{
		
		int[] temp =  new int[arr[0].length];
		int area = 0;
		int maxArea =  Integer.MIN_VALUE;
		
		for(int i=0; i<arr.length; i++)
		{
				for(int j=0; j<temp.length; j++)
				{
					
					if(arr[i][j]==0 )
						temp[j] = arr[i][j];
					else
						temp[j] = temp[j] + arr[i][j];
					
				}
				area = maxAreaUtil(temp);
				//System.out.println(area+" "+i);
				maxArea = maxArea>area?maxArea:area;
					
			
		}
		
		
		return maxArea;
		
	}

	public static void main(String args[])
		{
		
		MaxRectangle1s mr =  new MaxRectangle1s();
		
		int arr[][] = {{0, 1, 1, 0},
						{1, 1, 1, 1},
						{1, 1, 1, 1},
						{1, 1, 0, 0}};
		
		System.out.println(mr.maxRect(arr));
		}


}