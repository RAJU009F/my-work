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

class MinStackImplementation
	{
		Stack<Integer>  s =  new Stack<Integer>();
		int minEle;
		
		public void push(int x)
			{
				if(s.isEmpty())
				{
					s.push(x);
					minEle = x;
					
				}else if( minEle >x)
				{
					s.push(2*x-minEle);
					minEle = x;
					
					
					
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
					if( top < minEle )
					{
						int x  =  minEle;
						minEle = 2*minEle -top;
						return x;
					}
						
						return top;
					
				}
			}
		public int getMin()
			{
			
				if(s.isEmpty())
						return -1;
				return minEle;	
			
			}
		public static void main(String args[])
			{
			MinStackImplementation ms =  new MinStackImplementation();
				int arr[] = {10,8,6,12,16,4,7,3,2,20,1};
				for(int i=0; i<arr.length; i++)
						ms.push(arr[i]);
				while(!ms.s.isEmpty())	
				{	int min  =  ms.getMin();
					int top =  ms.pop();
				System.out.println("Min Elemnet "+min+" top  element "+top);
					
				}
				
			
			}
	
	
	
	}