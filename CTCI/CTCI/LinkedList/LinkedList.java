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
# Problem Statement	: insert %20 instead of spaces in a string
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

public void addNode(int data)
{
	Node node = new  Node(data);
	Node cur =  this;
	while(cur.next != null )
	{
		cur = cur.next;
		
	}
	
	cur.next = node;
	
	
	
}	

void printList()
{
	Node cur = this;
	
	while(cur != null)
	{
		System.out.print(cur.data+" ");
		cur = cur.next;
	}
			
}

void removeDuplicates()
{
	Node cur =  this;
	
	HashSet<Integer> hash =  new HashSet<Integer>();
	Node prev = null;
	while(cur.next != null)
	{
		
		if(!hash.contains(cur.data))
		{	hash.add(cur.data);
			prev =  cur;
			cur  = cur.next;
			
	
			}
		else
		{
			prev.next = cur.next;
			cur = prev.next;
			
			}
			
		
	}
	
	
	if(hash.contains(cur.data))
		prev.next = null;
	
	
}


void deleteDups()
{
	
	Node cur = this;
	
	while( cur !=null)
	{
		Node run = cur;
		
		while(run.next !=null)
		{
			if(run.next.data == cur.data)
			{
				run.next = run.next.next;
			}
			else
			{
				run = run.next;
			}
			
		}
		
		cur = cur.next;
		
	}
	
	
	
	
}



public void deleteNthNode(Node node)
{
	
		node.data = node.next.data;
		node.next = node.next.next;
	
	
}
	
public Node partition(int d)
{
	Node head = this;
	
	Node startL = null;
	Node endL = null;
	Node mid  = null;
	
	while(head !=null)
	{
		Node temp = head.next;
		head.next = null;
		if(head.data>d)
		{
			if(endL == null)
				endL = head;
			else
			{	head.next = endL;
				endL = head;}
			
		}else if(head.data < d)
		{
			if(startL == null)
			{
				startL = mid = head;
				
			}else
			{
				mid.next = head;
				mid = mid.next ;
			}
			
			
		}
		head = temp;
	}
	
	if(mid != null)
		mid.next = new Node(4);
	else
	{
		mid = new Node(4);
		//this = mid;
	}
	
	mid.next = endL;
	
	
 return startL;	
}	





	
}



class LinkedList
{
public static Node addLists(Node a,  Node b)
{
	
	if(a != null && b != null)
		return null;
	if(a != null)
		return b;
	if(b != null)
		return a;
	int carry =0;
	
	Node r = null;
	Node t  = null;
	while ( a !=null || b != null)
	{
		int x = (a !=null)? a.data:0;
		int y= (b !=null)? b.data:0;
		int s = (x+y+carry)%10;
		 carry = (x+y+carry)/10>0?1:0;
		
		if(r == null)
		{
				r = new Node(s+carry);
				t =r;
		}else
		{
			t.next = new Node(s+carry);
			
		}
		
		
		
		
	}
	
	if(carry>0)
		t.next = new Node(carry);
	
	
	return r;
	
}
	public static void main(String args[])
	{
		
		Node list =  new Node(1);
		list.addNode(7);
		list.addNode(6);
		// list.addNode(4);
		// list.addNode(5);
		// list.addNode(2);
		// list.addNode(3);
		// Node d = list.next.next;
		// print list
		/* list.printList();
		System.out.println(" "); */
		//list.removeDuplicates();
		// list.deleteDups();
		// list.printList();
		
		// System.out.println(" After Remove\n");
		//list.deleteNthNode(d);
		// list.printList();
		
		//Node list1 = list.partition(4);
		//list1.printList();
		
		Node list2 =  new Node(6);
		list2.addNode(8);
		list2.addNode(7);
		System.out.println("List1:\n");
		list.printList();
		System.out.println("List2:\n");
		list2.printList();
		Node res = addLists(list, list2);
		System.out.println("ResList:\n");
		res.printList();
		
		
	}



}