import java.lang.*;
import java.util.*;
import java.io.*;

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
// #include<queue>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	:   Circular DLL from BT
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/

class Node
	{
	
		Node l;
		Node r;
		int data;
		Node( int data)
			{
				this.data =  data;
				this.l = this.r = null;
			}
	
	}
	
class BTtoCircularDLL
	{
		Node root;
		
		Node head;
		Node prev;
		
		public  void printList(Node node)
		{
			Node cur = node;
			while(cur.r !=node)
			{
				System.out.print(node.data+" ");
				
			}
			
			System.out.println();
			
			
		}
		public void bttoDLL(Node node)
		{
			if(node == null)
				return;
			
			bttoDLL(node.l);
			if(prev == null)
			{
				head = node;
				prev = node;
			}else
			{
			node.r = prev;
			prev.l = node;
			}
			prev = node;
			
			bttoDLL(node.r);
			
		}
		public static void main(String args[])
		{
		BTtoCircularDLL bt =  new BTtoCircularDLL();
		
		bt.root =  new Node(4);
		bt.root.l =  new Node(2);
		bt.root.l.r  =  new Node(3);
		bt.root.l.l = new Node(1);
		bt.root.r  =  new Node(6);
		bt.root.r.l = new Node(5);
		bt.root.r.r = new Node(7);
		
		bt.bttoDLL(bt.root);
		
		System.out.println();
		bt.prev.r= bt.head;
		bt.head.l = bt.prev;
		bt.printList(bt.head);
		
		
		}
	}