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
# Topic or Type 	: GFG/Amazon
# Problem Statement	: 
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/

class Node
	{
	Node l;
	Node r;
	Node rand;
	int data;
	
	Node(int data)
	{
		this.data = data;
		this.l = this.r =  this.rand = null;
	
	}
	}
	
class CloneBT
		{
		
		Node root;
		
		public Node cloneTree(Node node, HashMap<Node , Node> hm)
		{
				if(node == null)
					return null;
				
				Node cnode =  new Node(node.data);
				hm.put(node, cnode);
				cnode.l =  cloneTree(node.l, hm);
				cnode.r = cloneTree(node.r,  hm);
				
				return cnode;
			
		}
		
		public void inorder(Node node)
		{
			if(node == null)
				return;
			inorder(node.l);
			System.out.print(node.data+"  ");
			inorder(node.r);
			
		}
		
		public void printRand(Node node)
		{
			if(node == null)
					return;
			if(node.rand != null)
					System.out.print(node.rand.data+" ");
			printRand(node.l);
			printRand(node.r);
				 
			
			
		}
		
		public static void main(String args[])
			{
				CloneBT bt =  new CloneBT();
				bt.root  =  new Node(1);
				bt.root.l  =  new Node(2);
				bt.root.r =  new Node(3);
				bt.root.l.l  =  new Node(4);
				bt.root.l.r  =  new Node(5);
				bt.root.r.l =  new  Node(6);
				bt.root.r.r =  new Node(7);
				
				bt.root.rand = bt.root.r.r;
				bt.root.l.rand = bt.root.l.l;
				bt.root.l.r.rand =  bt.root;
				bt.root.r.rand =  bt.root.l;
				System.out.println(" original tree");
				bt.inorder(bt.root);
				
				HashMap<Node, Node> hm = new HashMap<Node, Node>();
				Node croot =  bt.cloneTree(bt.root, hm);
				//bt.updateRand(hm, croot);
				
				Iterator<Map.Entry<Node, Node> > ente = hm.entrySet().iterator();
				
				// while(ente.hasNext())
				// {
					
					
				// }
				
				for ( Map.Entry<Node, Node> e : hm.entrySet() )
				{
					Node k =  e.getKey();
					Node v =  e.getValue();
					
					v.rand = k.rand;
				}
				System.out.println();
				System.out.println(" cloned tree");
				bt.inorder(croot);
				
				// print Rand pointers
				System.out.println("");
					System.out.println(" Rand pointeroriginal ");
				bt.printRand(bt.root);
				

				System.out.println("");
				System.out.println("cloned  Rand pointer");
				bt.printRand(croot);
				
				
				
		}
		
		}