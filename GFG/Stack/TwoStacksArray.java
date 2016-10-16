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
# Problem Statement	: Q with single Stack
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
*/

class TwoStacks
{
	int size;
	int arr[];
	int top1;
	int top2;
	
	
	TwoStacks(int n)
	{
		size = n;
		 arr = new int[n];
		top1 = -1;
		top2 = size;
		
	}
	
	
	void push1(int data)
	{
		if(top1<top2-1)
		{
			top1++;
			arr[top1] = data;
			
		}else
		{
			System.out.println("stack overflow");
		}
		
		
	}
	
	void push2(int data)
	{
		if(top1<top2-1)
		{
			top2--;
			arr[top2] = data;
		}else
		{
			System.out.println("stack overflow");
			
		}
		
		
	}
	
	int pop1()
	{
		if(top1==-1)
			return -1;
		return arr[top1--];
		
		
	}
	
	int pop2()
	{
		if(top2 == size)
			return -1;
		return arr[top2++];
		
	}
	
	public static void main(String args[])
	{
		TwoStacks ts =new  TwoStacks(5);
		ts.push1(5);
        ts.push2(10);
        ts.push2(15);
        ts.push1(11);
        ts.push2(7);
        System.out.println("Popped element from" +
                           " stack1 is " + ts.pop1());
        ts.push2(40);
        System.out.println("Popped element from" +
                         " stack2 is " + ts.pop2());
    
		
	}
}