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
# Problem Statement	: Pair wise reverse elements using linked lists
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
		this.next = null;
		this.data = data;		
	}
}


class PairwiseReverse
{
	
	Node head;
	
	public void push(int data)
	{
		Node node =  new Node(data);
		node.next =  head;
		head =  node;
		
	}
	
	public void pairWiseReverse(Node node)
	{
		if(node ==null || node.next == null)
			return;
		Node cur =  node;
		head =  cur.next;
		Node prev =  node.next;
		Node Next;
		
		//  swap first pair;
		
		cur.next =  prev.next;
		prev.next =  cur;
		prev =  cur;
		cur =  cur.next;
		
		while(cur!=null && cur.next!=null)
		{
			Next =  cur.next;
			
			prev.next =  Next;
			prev =  Next.next;
			Next.next =  cur;
			cur.next =  prev;
			prev =  cur;
			cur =  cur.next;
			
		}
		
		
		
	}
	public Node pairWiseReverseREC(Node node)
	{
		
		if(node == null || node.next == null)
				return node;
			
		Node remain =  node.next.next;
		Node newHead =  node.next;
		node.next.next =  node;
		node.next =  pairWiseReverseREC(remain);
		return newHead;
		
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
		PairwiseReverse ll = new PairwiseReverse();
		ll.push(7);
		ll.push(6);
		ll.push(5);
		ll.push(4);
		ll.push(3);
		ll.push(2);
		ll.push(1);
		
		ll.printList(ll.head);
		ll.pairWiseReverse(ll.head);
		ll.printList(ll.head);
		ll.head =  ll.pairWiseReverseREC(ll.head);
		ll.printList(ll.head);
		
	}
	
}