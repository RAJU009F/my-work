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
# Problem Statement	:  flip the BT in clock wise direction 
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
				this.l =  this.r = null;
				this.data = data;
			
			}
	
	}

class FlipBT
{
	Node root;
	
	public void levelOrderTraversal(Node node)	
	{
		if(node==null)
			return;
			
		Queue<Node> q =  new LinkedList<Node>();
		q.add(node);
		
		while(!q.isEmpty())
		{
			int n  = q.size();
			
			while(n-->0)
				{
				node  =  q.peek();
				q.poll();
				
				System.out.print(node.data+" ");
				if(node.l != null)
					q.add(node.l);
				if(node.r != null)
					q.add(node.r);
					
				
				}
			System.out.println();
		
		
		}
		
	
	
	}
	
	public Node flipTree(Node node)
		{
			if(node==null)
				return null;
				
			if(node.l == null &&  node.r  == null)
				return node;
		
			Node flipNode =  flipTree(node.l);
			
			node.l.l = node.r;
			node.l.r  = node;
			node.l = null;
			node.r  = null;
		
		return flipNode;
		}
	
	public static void main(String args[])
		{
			FlipBT bt =  new FlipBT();
			bt.root =  new Node(1);
			bt.root.l =  new Node(2);
			bt.root.r =  new Node(3);
			bt.root.l.l =  new Node(4);
			bt.root.l.r =  new Node(5);
			bt.root.l.l.l = new Node(6);
			bt.root.l.l.r =  new Node(7);
			bt.root.r =  new Node(8);
			bt.root.r.l = new Node(9);
			bt.root.r.r =  new Node(10);
			
			bt.levelOrderTraversal(bt.root);
			bt.root=bt.flipTree(bt.root);
			System.out.println("After Clock wise flip");
			bt.levelOrderTraversal(bt.root);
		}



}