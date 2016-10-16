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
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/LinkedList
# Problem Statement	: Decimal Equivalent of binary in Linked list
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Node
	{
		int data;
		Node next;
		
		Node(int data)
			{
			
			this.data = data;
			this.next =  null;
			}
	
	}
class DecimalEquivalent
{
		Node head ;

	public  void push(int data)	
	{
		
		Node node = new Node(data);
		node.next =  head;
		head = node;	
	}
	
	public int decimalEquivalent(Node node)
	{
		if(node == null)
				return 0;
		int res = 0;

		while(node != null)
		{
			res =  (res<<1) +  node.data;
			// System.out.print(node.data+" ");
			node =  node.next;	
			}
		return res;
	}
		
	public void printList(Node node)	
	{
		while(node !=null)
		{
			System.out.print(node.data+" ");
			
			node =  node.next;
		}
			
		System.out.println();
	}
	public static void main(String args[])
	{
	
		DecimalEquivalent ll =  new DecimalEquivalent();
	    ll.push(0);
		ll.push(1);
		ll.push(0);
		ll.push(0);
		ll.push(1);
		ll.push(1);
		ll.push(0);
		ll.push(0);
		ll.push(0);
		ll.printList(ll.head);
		System.out.println(ll.decimalEquivalent(ll.head));
	}
	
	
	
}
	