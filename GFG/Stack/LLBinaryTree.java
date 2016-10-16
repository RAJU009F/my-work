import java.io.*;
import java.lang.*;
import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
 // #include <stdlib.h>
 // #include <string.h>
 // #include<stdbool.h>
 // #include<limits.h>

// # // #include<iostream>
// # // #include<algorithm>
// # // #include<string>
// # // #include<vector>
// # // using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Stacks
# Problem Statement	: Linked List to binary tree conversion
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
*/


class Node{
	Node l;
	Node r;
	int data;

	 Node(int data)
	{
		this.data = data;
		this.l = null;
		this.r  = null;
		
	}	
	
}

class LNode{
	
	int data;
	LNode next;
	
	LNode(int data)
	{
		this.data = data;
		this.next = null;
		
	}
}

class LLBinaryTree{
	
	static Node root;
	static LNode head;
	public void push(int data)
	{
		LNode node =new  LNode(data);
		if(head ==null)
			head =node;
		else
			node.next = head;
			head = node;
		
		
	}
	
	public Node lltoBT()
	
	{
		Queue<Node>  q=  new LinkedList<Node>();
		
		Node parent = new Node(head.data);
		q.add(parent);
		head = head.next;
	
		while(head !=null)
			{
				Node temp = q.peek();
				q.poll();
				
				
				Node NodeLC = new Node(head.data);
				q.add(NodeLC);
				Node NodeRC = null;
					head = head.next;
				if(head!=null)
				{
					NodeRC = new Node(head.data);
					q.add(NodeRC);
					head = head.next;
					
					
				}
				temp.l = NodeLC;
				temp.r = NodeRC;
				
				
				
				
			}
			
		return parent;
	}
	
	public void inorder(Node node)
	{
		if(node !=null)
		{
			
			inorder(node.l);
			System.out.print(node.data+" ");
			inorder(node.r);
			
			
		}
		
		
	}
	
	
	public static void main(String args[])
	{
		
		LLBinaryTree bt = new LLBinaryTree();
		bt.push(1);
		bt.push(2);
		bt.push(3);
		bt.push(4);
		bt.push(4);
		bt.push(5);
		
		Node node = bt.lltoBT();
		bt.inorder(node);
	}
}
