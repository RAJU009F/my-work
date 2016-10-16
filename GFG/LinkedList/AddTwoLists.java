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
# Problem Statement	: Merge Sort
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
	}
}

class AddTwoLists
{
	Node head;
	
	
	public Node addLists(Node a, Node b)
	{
		int carry  = 0;
		Node res = null;
		Node cur = res;
		
		while(a !=null  || b!=null)
		{
			int data =  ((a!=null)?a.data:0) + ((b!=null) ? b.data:0);
			data +=carry;
			carry = data/10;
			data = data%10;
			
			Node node =  new Node(data);
			if(res ==null)
			{
				res = node;
				cur = res;
			}else
			{
				cur.next = node;
				cur = cur.next;
				
			}
			if(a !=null)
				a = a.next;
			if(b != null)
			b = b.next;
			
			
		}
		
		return res;
		
	}
	
	public void printList(Node list)
	{
		
		while(list !=null)
		{
			System.out.print(list.data+" ");
			list =  list.next;
		}
		
	}
	
	
	
	public static void main(String args[])
	{
		AddTwoLists l1 =  new AddTwoLists();
		l1.head = new Node(5);
		l1.head.next =  new Node(6);
		l1.head.next.next =  new Node(3);
		
		AddTwoLists l2 = new AddTwoLists();
		
		l2.head = new Node(8);
		l2.head.next =  new Node(4);
		l2.head.next.next =  new Node(2);
		
		AddTwoLists res =  new AddTwoLists();
		
		res.head =  res.addLists(l1.head, l2.head);
		l1.printList(l1.head);
		System.out.println();
		l2.printList(l2.head);
		System.out.println();
		res.printList(res.head);
		
		l1.head = new Node(7);
		l1.head.next = new Node(5);
		l1.head.next.next = new Node(9);
		l1.head.next.next.next = new Node(4);
		l1.head.next.next.next.next = new Node(6);
		l1.printList(l1.head);
		System.out.println();
		l2.head = new Node(8);
		l2.head.next =  new Node(4);
		l2.printList(l2.head);
		System.out.println();
		res.head =  res.addLists(l1.head, l2.head);
		res.printList(res.head);
       
		
	}
	
}