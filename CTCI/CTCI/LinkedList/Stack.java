import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: Java 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Node{
	
	int data;
	Node next;
	Node(int data)
	{
		this.data = data;
		this.next = null;
		
	}
	
	
	
}

class Stack1

{
	Node top;
	
	int  pop()
	{
		if(top !=null)
		{
			int  item = top.data;
			top = top.next;
			return item;
		}
		return -1;
	}
	
	
	void push(int  item)
	{
		if(top!=null)
		{
			Node t  = new Node(item);
			t.next  = top;
			top = t;;
		}
		else
		{
			top = new Node(item);
		}
		
	}
	
	int  peek()
	{
		return top.data;
	}
	
}

public class Stack
{
	public static void main(String args[])
	{
		Stack1 s  =  new Stack1();
		s.push(1);
		s.push(2);
		System.out.println(s.peek());
		System.out.println(s.pop());
		System.out.println(s.pop());System.out.println(s.pop());
		
	}
	
	
}