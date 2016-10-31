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
# Problem Statement	:  Sink ODD nodes in the BT
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
				this.data =  data;
				this.l =  this.r  = null;
			
			}
	}
	
class SinkOddNodesBT
		{
		
			Node root;
			
			public void inorder(Node node, int space)	
			{
				if(node==null)
						return;
					space +=10;
				inorder(node.l, space);
				System.out.println();
				for(int i=0; i<space; i++)
						System.out.print(" ");
				System.out.println(node.data+"  ");
				inorder(node.r,space);
				
				
			}
			public void sink(Node node)
				{
					if(node == null)
						return ;
					if(node.l==null&& node.r==null)
						return;
					if(node.l != null && ((node.l.data&1)!=1))
							{
								int t  =  node.data;
								node.data =  node.l.data;
								node.l.data =  t;
								sink(node.l);
							
							}
					else if(node.r !=null && (node.r.data &1)!=1)
						{
								int t  =  node.data;
								node.data =  node.r.data;
								node.r.data =  t;
								sink(node.r);
						
						}
				
				
				}
			
			public void sinkOddNodes(Node node)
				{
					if(node == null)
						return;
					sinkOddNodes(node.l);
					sinkOddNodes(node.r);
					if((node.data&1)==1)
						sink(node);
						
				
				
				}
			public static void main(String args[])
				{
				
					SinkOddNodesBT bt =  new SinkOddNodesBT();
					bt.root =  new Node(1);
					bt.root.l = new Node(2);
					bt.root.r =  new Node(3);
					bt.root.l.l =  new Node(4);
					bt.root.l.r =  new Node(5);
					bt.root.r.l =  new Node(6);
					bt.root.r.r  =  new Node(7);
					
					bt.inorder(bt.root, 10);
					
					System.out.println("After ");
					bt.sinkOddNodes(bt.root);
					bt.inorder(bt.root, 10);
				
				}
		
		}