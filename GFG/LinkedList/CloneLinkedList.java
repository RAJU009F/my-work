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
# Problem Statement	: Clone the linked list with a random pointer
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class CloneLinkedList
{
	Node head;
	
	class Node
	{
		
		int data;
		Node next;
		Node rand;
		
		Node(int data)
		{
			this.data = data;
			this.next = null;
			this.rand = null;
			
		}
		
	}
	
	public void push(int data)
	{
		Node node =  new Node(data);
		node.next = head;
		head = node;
		
	}
	
	public static Node cloneList(Node node)
	{
		if(node == null)
			return null;
		Node newHead = node;
		Node orig = node;
		Node cur =  newHead;
		while(orig !=null)
			
		{	cur = orig;
			cur.next =  orig.next;
			cur.rand = orig;
			orig =  orig.next;
		}
		
		// update the next points in original list
		
		
		cur =  newHead;
		orig = node;
		
		while(orig != null )
		 {
			Node temp = orig.next;
			orig.next = cur;
			 cur =  cur.next;
			 orig =  temp;
			
			
		 }
		
		
		update the random pointers
		
		cur =  newHead;
		 orig =  node;
		 while(cur !=null)
		 {
			cur.rand =  cur.rand.rand.next;
			cur =  cur.next;
			
		 }
		
		return newHead;
		
	}
	
	public void printList(Node node)
	{
		while(node !=null)
		{
			System.out.print(node.data+" ");
			node =  node.next;
			
		}
		
	}
	
	public static void main(String args[])
	{
		CloneLinkedList ll =  new CloneLinkedList();
		ll.push(5);
		ll.push(4);
		ll.push(3);
		ll.push(2);
		ll.push(1);
		
	//  update the rand pointers
	
		ll.head.rand =  ll.head.next.next;
		ll.head.next.rand = ll.head;
		ll.head.next.next.rand = ll.head.rand.next.next;
		ll.head.next.next.next.rand = ll.head.rand;
		ll.head.next.next.next.next.rand = ll.head.next;
			ll.printList(ll.head);
		CloneLinkedList ll1 =  new CloneLinkedList();
		ll1.head = ll.cloneList(ll.head);
	
		ll.printList(ll1.head);
		
	}
	
}