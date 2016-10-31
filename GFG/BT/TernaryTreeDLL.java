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
# Problem Statement	:  ternary tree to DLL
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
		Node p;
		Node( int data)
			{
				this.data = data;
				this.p = this.l =  this.r  = null;
			
			}
			
		
	}
	
class TernaryTreeDLL 
		{
			Node root;
			Node head =null;
			Node tail=null;
			
			public void TTtoDLL(Node node )
			{
				if(node == null)
						return ;
					
				Node left =  node.l;
				Node right =  node.r;
				Node parent =  node.p;
				
					if( head == null)
					{
						head =  node;
						tail = node;
					}else
						
						{
							node.l = tail ;
							
							node.r= node.p =tail.p = null;
							tail.r = node;
							tail = tail.r;							
						}
			
				TTtoDLL(left);
				TTtoDLL(parent);
				TTtoDLL(right);
				
				
				
				
			}
			
			public void printList(Node node)
				{
					while(node != null)
						{
							System.out.print(node.data+" ");
							node =  node.r;
						}
				}
			
			public static void main(String args[] )
			{
				TernaryTreeDLL bt =  new TernaryTreeDLL();
				bt.root =  new Node(1);
				bt.root.l =  new Node(2);
				bt.root.p =  new Node(3);
				bt.root.r =  new Node(4);
				bt.root.l.l = new Node(5);
				bt.root.l.p = new Node(6);
				bt.root.l.r  =  new Node(7);
				bt.root.p.l =  new Node(8);
				bt.root.p.p =  new Node(9);
				bt.root.p.r = new Node(10);
				
				bt.root.r.l = new Node(11);
				bt.root.r.p = new Node(12);
				bt.root.r.r = new Node(13);
				
			 bt.TTtoDLL(bt.root);
			
			bt.printList(bt.head);
			
			}
	
		
		
		}