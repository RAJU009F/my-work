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
# Problem Statement	: Delete the given node without head refernce
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
		this.next = null;
	}
	
}

class DeleteNodeReferencedNode
{
	public  static  Node head;
	public static void deleteReferencedNode(Node nodeRef)
	{
		if(nodeRef == null)
			return;
		
		if(nodeRef.next!=null){
			nodeRef.data = nodeRef.next.data;
			nodeRef.next = nodeRef.next.next;
		}else
				nodeRef =null;
		
		
	}
	
	public static  void printLL(Node node)
	{
		
		while(node !=null)
		{
			
			System.out.print(node.data+" ");
			node = node.next;
			
		}
		
		System.out.println();
	}
	
	public  void findMiddle(Node node)
	{
		
		Node mid =  node;
		Node last = node;
		
		while(last.next !=null && last.next.next !=null)
		{
			last  =  last.next.next;
			mid =  mid.next;
			
		}
		
		System.out.println(mid.data);
	}
	
		public  void findMiddleUsingCount(Node node)
	{
		
		Node mid  = node;
		int count = 0;
		while(node != null)
		{
			if((count&1)==1)
				mid =  mid.next;
			node =  node.next;
			count++;
			
		}
		
		System.out.println(mid.data);
	}
	
	public static void main(String args[])
	{
	
		DeleteNodeReferencedNode ll =  new DeleteNodeReferencedNode();
		
			ll.head =  new Node(10);
			ll.head.next =  new Node(20);
			ll.head.next.next  =  new Node(30);
			ll.head.next.next.next  = new Node(40);
			ll.head.next.next.next.next = new Node(50);
			ll.head.next.next.next.next.next = new Node(60);
			ll.head.next.next.next.next.next.next = new Node(70);
			ll.head.next.next.next.next.next.next.next = new Node(80);
		printLL(ll.head);		
		//deleteReferencedNode(ll.head.next.next.next.next.next.next);
			printLL(ll.head);	
			
			ll.findMiddle(ll.head);
			ll.findMiddleUsingCount(ll.head);
	}
	
	
	
}

