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
# Problem Statement	: Rearrange Lonkedlist in zigzag
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
	Node next ;
	
	Node(int data)
	{
		this.data = data;
		this.next = null;
	}
	
}

class ZigZagLinkedList
{
		Node head;
			
	 		
	public  void push(int data)
	{
		Node node =  new Node(data);
		node.next =  head;
		head =  node;
	
	}
	public void makeZigZag(Node node)
	{
		if(node == null ||  node.next == null)
			return;
		boolean flag = true;
		while(node != null  && node.next !=null)
		{
			if(flag)
			{
				if(node.data>node.next.data)
				{
					int t =  node.data;
					node.data =  node.next.data;
					node.next.data =t;
					
				}
				flag = !flag;
				
			}else{
				if(node.data<node.next.data)
				{
					int t =  node.data;
					node.data =  node.next.data;
					node.next.data =t;
					
				}
				
				flag =  !flag;
			}
				
			node  =  node.next;
		}
		
	}
			public void printList(Node node)
		{
			while(node != null)
			{
				System.out.print(node.data+" ");
				node =  node.next;
				
			}
			
			System.out.println();
			
		}
	public static void main(String args[])
	{
		ZigZagLinkedList ll = new ZigZagLinkedList();
		ll.push(9);
		ll.push(7);
		ll.push(6);
		ll.push(5);
		ll.push(4);
		ll.push(3);
		ll.push(2);
		ll.push(1);
		ll.push(0);
		ll.printList(ll.head);	
		ll.makeZigZag(ll.head);
		ll.printList(ll.head);
	}
	
	
}