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
# Problem Statement	:  Print all the cousins except the siblings
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
		
		Node(int data)
			{
				this.l = null;
				this.r = null;
				this.data = data;
			
			}
		

		
	
	}
	
class Util
{
	Node parent;
	int level=0;
	
}
	
class SiblingsBT
		{
			Node root;
			
			public void  getParentLevel(Node node, Node target, Util u, int level)
			{
				if(node == null )
					return;
				if( node.l == target || node.r ==target )
				{
					u.parent = node;
					u.level = level+1;
					return;
				}
				else
				{		
				getParentLevel(node.l, target, u, level+1);
				getParentLevel(node.r, target, u, level+1);
				}
			}
			
			public void printSiblingsBTUtil(Node node, Util u, int level)
			{
				if(node == null)
						return;
				if(node == u.parent)
						return;
				else if( level == u.level)
						System.out.print(node.data+" ");
				printSiblingsBTUtil(node.l, u, level+1);
				printSiblingsBTUtil(node.r, u, level+1);
				
			}
			
			public void printSiblingsBT(Node node, Node target)
				{
					if(node== null)
						return;
					Util u  =  new Util();
					u.parent = null;
					u.level = 0;
					getParentLevel(node, target, u, 0);
					printSiblingsBTUtil(node,  u, 0);
					
					
						
				}
			
			public static void main(String args[])
				{
				
					SiblingsBT bt = new SiblingsBT();
					bt.root =  new Node(1);
					bt.root.l  =  new Node(2);
					bt.root.r =  new Node(3);
					bt.root.l.l = new Node(4);
					bt.root.l.r =  new Node(5);
					bt.root.r.l = new Node(6);
					bt.root.r.r = new Node(7);
				
					bt.printSiblingsBT(bt.root, bt.root.l.r);
				}
		
		}

