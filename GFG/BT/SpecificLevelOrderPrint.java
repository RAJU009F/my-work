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
# Problem Statement	:  Specific level order print of FULL BT form bottom to top
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
				this.l = null;
				this.r = null;
				this.data = data;	
			}
	
	
	}

class SpecificLevelOrderPrint
	{
		Node root;
		
		public void specificPrintUtil(Node node, Stack<Node> s)
		{
			Queue<Node> q =  new LinkedList<Node>();
			q.add(node.l);
			q.add(node.r);
			
			while(!q.isEmpty())
			{
				Node node1 = q.peek();
				q.poll();
				
				Node node2 =  q.peek();
				q.poll();			
				s.push(node2.l);
				s.push(node1.r);
				s.push(node2.r);
				s.push(node1.l);
				if(node1.l.l !=null)
				{
					
					q.add(node1.r);
					q.add(node2.l);
					q.add(node1.l);
					q.add(node2.r);					
				}	
			}			
		}
		public void specificPrint(Node node)
			{
				if(node == null)
					return;
				Stack<Node> s  =  new Stack<Node>();
				s.push(node);
				if(node.l !=null)
					{
						s.push(node.r);
						s.push(node.l);
					}
				if(node.l.l !=null)
							specificPrintUtil(node, s);
				int i=0;
				while(!s.isEmpty())
				{

					System.out.print(s.pop().data+"  ");
					
				}
			
			}
		
		public static void main(String args[]){
		SpecificLevelOrderPrint tree =  new SpecificLevelOrderPrint();
		tree.root =  new Node(1);
		tree.root.l =  new Node(2);
		tree.root.r = new Node(3);
 
		tree.root.l.l  = new Node(4);
        tree.root.l.r = new Node(5);
        tree.root.r.l  = new Node(6);
        tree.root.r.r = new Node(7);
  
        tree.root.l.l.l  = new Node(8);
        tree.root.l.l.r  = new Node(9);
        tree.root.l.r.l  = new Node(10);
        tree.root.l.r.r  = new Node(11);
        tree.root.r.l.l  = new Node(12);
        tree.root.r.l.r  = new Node(13);
        tree.root.r.r.l  = new Node(14);
        tree.root.r.r.r  = new Node(15);
  
        tree.root.l.l.l.l  = new Node(16);
        tree.root.l.l.l.r  = new Node(17);
        tree.root.l.l.r.l  = new Node(18);
        tree.root.l.l.r.r  = new Node(19);
        tree.root.l.r.l.l  = new Node(20);
        tree.root.l.r.l.r  = new Node(21);
        tree.root.l.r.r.l  = new Node(22);
        tree.root.l.r.r.r  = new Node(23);
        tree.root.r.l.l.l  = new Node(24);
        tree.root.r.l.l.r  = new Node(25);
        tree.root.r.l.r.l  = new Node(26);
        tree.root.r.l.r.r  = new Node(27);
        tree.root.r.r.l.l  = new Node(28);
        tree.root.r.r.l.r  = new Node(29);
        tree.root.r.r.r.l  = new Node(30);
        tree.root.r.r.r.r  = new Node(31);
     
		tree.specificPrint(tree.root);
		
		}
	}