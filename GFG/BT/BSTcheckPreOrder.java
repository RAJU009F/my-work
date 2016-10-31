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
# Topic or Type 	: GFG/BT
# Problem Statement	:  is the given preorder represtn BST or not
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/





class BSTcheckPreOrder
	{
		
		
		public static  boolean isBST(int pre[])
		{
			//int n  = pre.length;
			
			Stack<Integer> s =  new Stack<Integer>();
			int root = Integer.MIN_VALUE;
			
			for(int i=0; i<pre.length; i++)
			{
				if(pre[i]<root)
						return false;
				
				while(!s.isEmpty() && s.peek()<pre[i])
				{
					root = s.pop();
					// s.poll();
					
				}
				s.push(pre[i]);
			}
			
			return true;
		
		}
	
	
		public static void main(String args[])
			{
				int pre[] = {40, 30, 35, 80, 100};
			
				System.out.println(isBST(pre));
				int pre1[] = {40, 30, 35, 20, 80, 100};
			
				System.out.println(isBST(pre1));
				
				
			}
	
	}