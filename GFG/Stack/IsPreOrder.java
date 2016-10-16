import java.io.*;
import java.lang.*;
import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
 // #include <stdlib.h>
 // #include <string.h>
 // #include<stdbool.h>
 // #include<limits.h>

// # // #include<iostream>
// # // #include<algorithm>
// # // #include<string>
// # // #include<vector>
// # // using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Stacks
# Problem Statement	: check if pre orrder traversal of BST or not
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
*/

class  IsPreOrder
{

	static boolean isPreOrder(int pre[],  int n)
	{
		Stack<Integer> s =  new Stack<Integer>();
		int root = Integer.MIN_VALUE;
		
		for(int i=0; i<n ;i++)
		{
			if(pre[i]<root)
				return false;
			
			while(!s.isEmpty() && s.peek() <=pre[i])
			{
				root = s.peek();
				s.pop();
				
			}
			s.push(pre[i]);
		}
		
		
		return true;
	}
	public static void main(String args[])
	{
		int pre[] = {5,3,2,1,4,8,7,6,10,9};
		System.out.println(isPreOrder(pre, pre.length));
		
		int pre1[] = {40, 30, 35, 20, 80, 100};
		System.out.println(isPreOrder(pre1, pre1.length));
	}


}


