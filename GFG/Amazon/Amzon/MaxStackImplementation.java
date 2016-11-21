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
# Problem Statement	: implement  Stack 
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/

class MaxStackImplementation
	{
	
		Stack<Integer>  s =  new Stack<Integer>();
		int maxEle;
		
		public void push(int x)
			{
				if(s.isEmpty())
				{
					s.push(x);
					maxEle = x;
					
				}else if( maxEle <x)
				{
					s.push(2*x-maxEle);
					maxEle = x;
					
					
					
				}else
						s.push(x);
						
			
			}
		public int pop()
			{
				if(s.isEmpty())
						return -1;
				else 
				{
					int top = s.peek();
							s.pop();
					if( top > maxEle )
					{
						int x  =  maxEle;
						maxEle = 2*maxEle -top;
						return x;
					}
						
						return top;
					
				}
			}
		public int getMax()
			{
			
				if(s.isEmpty())
						return -1;
				return maxEle;	
			
			}
		public static void main(String args[])
			{
			MaxStackImplementation ms =  new MaxStackImplementation();
				int arr[] = {10,8,6,12,16,4,7,3,2,20,1};
				for(int i=0; i<arr.length; i++)
						ms.push(arr[i]);
				while(!ms.s.isEmpty())	
				{	int min  =  ms.getMax();
					int top =  ms.pop();
				System.out.println("Max Elemnet "+min+" top  element "+top);
					
				}
				
			
			}
	
	}