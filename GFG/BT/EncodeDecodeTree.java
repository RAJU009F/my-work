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
# Problem Statement	:  Succenet tree / encoding the tree
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
			this.data = data;
			this.l = this.r = null;
			
		}
	}
	
class EncodeDecodeTree
		{
			Node root;
			
			public void  encodeTree(Node root, LinkedList<Integer> list, LinkedList<Integer> struct)
			{
				
				if(root == null)
				{struct.addLast(0);
					return;
				}
				else
				{
				struct.addLast(1);
				list.addLast(root.data);
				encodeTree(root.l, list, struct);
				encodeTree(root.r, list, struct);
				}
				
			}
			
			public Node decodeTree(LinkedList<Integer> list, LinkedList<Integer> struct)
			{
				if(struct.size() == 0)
				{
					return null;
				}
				
				int b = struct.get(0);
				struct.remove(0);
				
				if(b == 1)
				{
					int data = list.getFirst();
										list.remove(0);
					Node node =  new Node(data);

					node.l = decodeTree(list, struct);
					node.r = decodeTree(list, struct);
					return node;
					
				}
				
				return null;
			}
			
			
			public void preorder(Node node)
			{
				if(node == null)
					return;
				System.out.print(node.data + "  ");
				preorder(node.l);
				preorder(node.r);
				
				
				
			}
			public static void main(String args[])
				{
					EncodeDecodeTree bt =  new EncodeDecodeTree();
					bt. root = new  Node(10);
				bt.root.l         = new Node(20);
				bt.root.r        = new Node(30);
				bt.root.l.l   = new Node(40);
				bt.root.l.r  = new Node(50);
				bt.root.r.r = new Node(70);
					LinkedList<Integer> list =  new LinkedList<Integer>();
					LinkedList<Integer> struct =  new LinkedList<Integer>();
					
					bt.encodeTree(bt.root,  list,  struct);
					bt.root = bt.decodeTree( list, struct);
					bt.preorder(bt.root);
					
				}
				
		
		}
