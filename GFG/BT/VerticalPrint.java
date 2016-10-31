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
# Problem Statement	: print the nodes in vertically
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

class VerticalPrint
		{
		
			Node root;
			
			public void verticalPrintUtil(Node node, int i,  HashMap<Integer, LinkedList<Node>> hm)
			{
				if(node == null)
					return;
				if(hm.get(i) == null)
				{
					LinkedList<Node> list  =  new LinkedList<Node>();
					list.add(node);
					hm.put(i, list);
				}
				else
					
					{
						
						LinkedList<Node> list =  hm.get(i);
						list.add(node);
						hm.put(i, list);
 						
					}
			verticalPrintUtil(node.l, i-1, hm);
			verticalPrintUtil(node.r, i+1, hm);
				
				
				
			}
			public void verticalPrint(Node node)
			{
				if(node == null)
					return;
			HashMap<Integer, LinkedList<Node>> hm =  new HashMap<Integer, LinkedList<Node>>();	
				verticalPrintUtil(node, 0, hm);
				
			for (Map.Entry<Integer, LinkedList<Node>> e: hm.entrySet())
			{
				int k = e.getKey();
				LinkedList<Node> nodes = e.getValue();
				
				Iterator<Node> it = nodes.iterator();
				while(it.hasNext())
					 System.out.print(it.next().data+" ");
				System.out.println();
			}
				
			}
			
			public static void main(String args[])
			{
				VerticalPrint bt =  new VerticalPrint();
				bt.root = new Node(1);
				bt.root.l = new Node(2);
				bt.root.r = new Node(3);
				bt.root.l.l = new Node(4);
				bt.root.l.r = new Node(5);
				bt.root.r.l =  new Node(6);
				bt.root.r.r = new Node(7);
				
			bt.verticalPrint(bt.root);
			}
		
		
		}