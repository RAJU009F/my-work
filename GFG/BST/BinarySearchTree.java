import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BST
# Problem Statement	: Java: 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class Node {

	int  data;
	Node l;
	Node r;
	
	Node (int data)
	{
		this.data = data;
		this.l = null;
		this.r =  null;
	}

}

class BinarySearchTree

{
	static Node root; 
	
	
	int Ceil(Node node, int key)
	{
		if(node == null)
			return -1;
		
	
		
	
			if(node.data<key)
			return Ceil(node.r, key);
		
			if(node.data == key)
			return node.data;
		
		int c = Ceil(node.l, key);
		
		return (c>=key)?c:node.data;
		
		
		
		
	}
	
	// int ceil1(Node node, Node pre, int key)
	// {
		// if(node == null)
			// return -1;
		
		
		// int c = ceil(node.r, pre, key);
		// if(c != -1)
				// return c;
		// if(pre != null && node.data<key)
				// return pre.data;
		// pre = node;	
		
		// return ceil(node.l, pre, key);
		
	// }
	
	int Floor(Node node, int key)
	{
		
		if( node == null)
			return -1;
		
		if(root.data>key)
			return floor(node.l, key);
		if(node.data == key)
			return node.data;
		
		int f = floor(node.r, key);
		
		return f<=key?f:node.data;
		
		
		
	}
	
	int floor(Node node,  int key)
	{
		if(node == null)
			return -1;
		int v=-1;
		boolean found = false;
		while(node != null)
		{
			if(node.data == key)
				return node.data;
			else if(node.data > key)
				node = node.l;
			else if(node.data < key)
			{
				found = true;
				v = node.data;
				node =  node.r;
				
			}
			
			
			
		}
		
		if(found)
			return v;
		else
			return -1;	
	}
	
int ceil(Node node, int key)
{
	if(node == null)
		return -1;
	
	int v = -1;
	boolean found = false;
	while(node != null)
	{
		if(node.data == key)
			return node.data;
		else if(node.data<key)
			node = node.r;
		else if(node.data>key)
		{
			v = node.data;
			found = true;
			node = node.l;	
		}		
	}
	
	if( found)
		return v;
	else
		return -1;
	
	
	
}
	
	public static void main(String args[])
	
	{
		
		BinarySearchTree tree =  new BinarySearchTree();
		
		tree.root = new Node(8);
		tree.root.l = new Node(4);
		tree.root.r = new Node(12);
        tree.root.l.l = new Node(2);
        tree.root.l.r = new Node(6);
        tree.root.r.l = new Node(10);
        tree.root.r.r = new Node(14);
        for (int i = 0; i < 16; i++) {
            System.out.println("Ceil:"+i + " " + tree.ceil(root, i));
			//System.out.println("ceil:" + i + " " + tree.ceil(root,null, i));
			System.out.println();
			
			System.out.println("floor:" + i + " " + tree.floor(root, i));
        }
		
	}
		
	
	
	
	
	
}
