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
# Problem Statement	:  Stock Span Problem
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/

class Node
	{
		int data;
		Node l;
		Node r;
		
		Node(int data)
			{
				this.data = data;
				this.l =  this.r = null;
			
			}
	
	}
	
class StockSpan	

{
	public void printStockSpan(int price[])
	{
		
		int n =  price.length;
		
		int[] S =  new int[n];
		
		Stack<Integer> s=  new Stack<Integer>();
		s.push(0);
		for(int i=1; i<n; i++)
		{
			while(!s.isEmpty() && price[s.peek()]<=price[i])
				s.pop();
			
			S[i] = s.isEmpty()?i+1:i-s.peek();
			s.push(i);
		}
		
		
		for(int i=0; i<n; i++)
			System.out.print(S[i] + " ");
		
	}
	
	public static void main(String args[])
	{
		
		StockSpan ss  =  new StockSpan();
		
		int price[] = {10,5,4,90,100,200,400,500,150,100,200};
			
		ss.printStockSpan(price);
		
		
	}








}