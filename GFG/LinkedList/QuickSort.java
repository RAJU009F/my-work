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
# Problem Statement	: Quicksort Double linked list
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
	Node prev;
	
	Node(int data)
	{
		this.data = data;
		this.next =  null;
		this.prev = null;
		
	}
	
	
}

class QuickSort
{
	Node head;
	
	public void push(int data)
	{
		if(head == null)
			head =  new Node(data);
		else
		{
		Node node =  new Node(data);
		node.next =  head;
		head.prev = node;
		head =  node;
		}
	}
	
	public void printList( Node node)
	{
		while(node !=null)
		{
			
			System.out.print(" "+node.data);
			node =  node.next;
		}
		System.out.println();
	}
	
	public Node parttion(Node l, Node r)
	{
		int x = r.data;
		
		Node i = l.prev;
		
		for(Node j = l; j!=r; j=j.next)
		{
			if(x>= j.data)
			{
				i = (i!=null)?i.next:l;
				
				int t =  i.data;
				i.data = j.data;
				j.data = t;
				
				
			}
			
			
				
			
		}
		i = (i!=null)?i.next:l;
				
				int t =  i.data;
				i.data = r.data;
				r.data = t;
		
		return i;
	}
	
	public  void quicksort(Node l, Node r)
	{
		if(l!=null && r != null && l!=r && l.next != r)
		{
			Node pivot =  parttion(l, r);
			quicksort(l, pivot.prev);
			quicksort(pivot.next, r);
			
		}
	}
	
	public void sort(Node node)
	{
		if(node == null || node.next == null)
			return;
		Node lastNode = node;
		while(lastNode.next != null)
			lastNode =  lastNode.next;
		quicksort(node, lastNode);
		
		
	}
	
	public static void main(String args[])
	{
		QuickSort qs  =  new QuickSort();
		qs.push(1);
		qs.push(5);
		qs.push(20);
		qs.push(3);
		qs.push(30);
		qs.push(4);
		
		qs.printList(qs.head);
		
		qs.sort(qs.head);
		qs.printList(qs.head);
			
	}
	
	
	
	
}
