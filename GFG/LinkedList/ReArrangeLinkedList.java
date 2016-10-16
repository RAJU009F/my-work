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
# Problem Statement	: Rearrange Lonkedlist in L1->Ln->L2->ln-1->l3->ln-2.....
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

class ReArrangeLinkedList
	{
		Node head;
		
		public void push(int data)
		{
				Node node =  new Node(data);
				node.next = head;
				head=  node;				
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
		public void reArrange(Node node)
		{
			if(node==null || node.next == null)
					return;
			// split the list:
			
			Node mid = node;
			Node last = node;
			
			Node list1 = node;
			while(last.next!=null && last.next.next!=null)
			{
				mid =  mid.next;
				last =  last.next.next;
				
			}
			Node list2  = mid.next;
			mid.next = null;
			
			// reverse 2nd list
			
			Node prev = null;
			Node temp = null;
			
			while(list2 !=null){
					temp  = prev;
					prev =  list2;
					list2 =  list2.next;
					prev.next =  temp;
				
			}
			
			list2 =  prev;
			
			
			// reaarnge or merge 
			
			Node next1;
			Node next2;
			
			while(	list1!=null && list2!=null)
			{
				next1 =  list1.next;
				next2 =  list2.next;
				
				list2.next = next1;
					list1.next =  list2;
				
				list1 = next1;
				list2 =  next2;
				
				
			}
			
			head =  node;
			
		}
		
		public static void main(String args[])
			{
				ReArrangeLinkedList ll =  new ReArrangeLinkedList();
				ll.push(1);
				ll.push(2);
				ll.push(3);
				ll.push(4);
				ll.push(5);
				ll.push(6);
				ll.push(7);
				
				ll.printList(ll.head);
				ll.reArrange(ll.head);
				ll.printList(ll.head);
				
			}
	}