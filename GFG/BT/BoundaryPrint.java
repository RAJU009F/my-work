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
# Topic or Type 	: GFG/BT
# Problem Statement	: print  boundary nodes
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
	
	int data;
	Node l;
	Node r;
	
	Node(int data)
	{
		this.data = data;
		this.l = null;
		this.r =  null;
	}
	
}


class  BoundaryPrint
{
	
	
		Node root;
		
		public void printAllLeafNodes(Node node)
		{
			if(node ==null)
				return;
			if(node.l == null && node.r == null)
			{
				System.out.print(node.data+" ");
			}else
			{
				printAllLeafNodes(node.l);
				printAllLeafNodes(node.r);
				
			}
			
			
		}
	
		
		public void printLeftMostNodes(Node node)
		{
			if(node == null)
				return;
			
			if(node.l != null)
			{
				System.out.print(node.data+" ");
				printLeftMostNodes(node.l);
				
			}else if(node.r !=null)
			{
				System.out.print(node.data + " ");
				printLeftMostNodes(node.r);
				
			}
		}
		
		public void printRightMostNodes(Node node)
		{
			if(node == null)
				return;
			if(node.r !=null)
			{
				printRightMostNodes(node.r);
				System.out.print(node.data+" ");
				
			}else if(node.l != null)
			{
				printRightMostNodes(node.l);
				System.out.print(node.data+" ");
				
			}
			
		}
		
		public void printBoundary(Node node)
		{
			if(node == null)
				return;
			// print left most nodes from root first before last non leaf
			
			Node cur = node;
			
			printLeftMostNodes(node);
			
			//  print all leaf nodes from left to right
			
			printAllLeafNodes(root);
			
			// print right most nodes until leaf node
			printRightMostNodes(root.r);
			
			
			
			
		}
		public static void main(String args[])
		{
		BoundaryPrint bt =  new BoundaryPrint(); 
		bt.root =  new Node(10);
		bt.root.l = new Node(11);
		bt.root.l.l = new Node(12);
		bt.root.l.l.r = new Node(13);
		bt.root.l.l.r.l =  new Node(17);
		bt.root.l.l.r.r =  new Node(14);
		bt.root.l.l.r.l.r =  new Node(9);
		
		bt.root.l.r = new Node(1);
		bt.root.l.r.l =  new Node(6);
		bt.root.l.r.r = new Node(7);
		
		
		bt.root.r =  new Node(200);
		bt.root.r.l =  new Node(201);
		bt.root.r.r =  new Node(300);
		bt.root.r.r.r = new Node(500);
		
		bt.root.r.l.l =  new Node(400);
		bt.root.r.l.r =  new Node(401);
		
		bt.printBoundary(bt.root);
		
		}
		
		
	
}