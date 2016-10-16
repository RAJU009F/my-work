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
# Problem Statement	: Merge Linked Lists
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
		this.next =  null;
		this.data =  data;
		
	}
	
	
	
}

class MergeTwoLinkedList

{
	Node head;
	public void push(int data)
	{	
		Node node =  new Node(data);
		node.next =  head;
		head =  node;
	}	
	
	// 
		
	public  void mergeLists(Node head1, Node head2)	
	{
		if(head1 ==null  || head2 == null)
				return;

		Node cur1 =  head1;
		Node cur2 = head2;
		
	
			Node cur1Next =  cur1.next;
					Node cur2Next =  cur2.next;
		while(cur1!=null && cur2!=null)
		{
				cur1Next =  cur1.next;
				cur2Next =  cur2.next;
					
					cur2.next = cur1Next;
					cur1.next =  cur2;
				
				cur1 =  cur1Next;
				cur2 =  cur2Next;
		}
		
		head =  cur2Next;
		
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
			MergeTwoLinkedList l1 =  new MergeTwoLinkedList();			
			l1.push(7);
			l1.push(6);
			l1.push(5);
			l1.push(4);
			l1.push(3);
			l1.push(2);
			l1.push(1);
			MergeTwoLinkedList l2 =  new MergeTwoLinkedList();
			l2.push(40);
			l2.push(30);
			l2.push(20);
			l2.push(10);
				l1.printList(l1.head);
			
			l2.printList(l2.head);
			
		
			l2.mergeLists(l1.head,  l2.head);
			l1.printList(l1.head);
			
			l2.printList(l2.head);
		
	}
	
}
