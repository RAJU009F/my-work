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
# Problem Statement	: Java : BST from PreORDER
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Node {
	
	int data;
	Node l;
	Node r;
	
	Node(int data)
	{
		
		this.data = data;
		this.l = this.r = null;
		
	}

}




class BSTfromPreOrder

{

	static  Node root;

public  void preOrder(Node node)
{
	if(node == null)
		return;
	
	Stack<Node> s =  new Stack<Node>();
	
	while(true)
	{
		while(node != null)
		{
			System.out.print(node.data + " ");
			s.push(node);
			node = node.l;
			
			
		}
		
		if(s.isEmpty() == true)
			break;
		else
		{
			node = s.pop();
			node =  node.r;
			
		}
		
		
		
	}
	
	
}

public  Node construct(int pre[],  int len)
{
	Stack<Node> s =  new Stack<Node>();
	
	Node root =  new Node(pre[0]);
	s.push(root);
	
	for(int i=1; i<len; i++)
	{
		Node temp = null;
		
		while( !s.isEmpty() && s.peek().data<pre[i])
		{
			temp = s.pop();
		}
		
		if(temp != null)
		{
			temp.r = new Node(pre[i]);
			s.push(temp.r);
			
		}else
		{
			temp = s.peek();
			temp.l =  new Node(pre[i]);
			s.push(temp.l);
			
		}
		
	}
	
	return root;
	
}


public void inOrder(Node node)
{
	if(node == null)
		return ;
	
	Stack<Node> s =  new Stack<Node>();
	
	while(true)
	{
		while(node != null)
		{
			s.push(node);
			node =  node.l;
						
		}
		
		if(s.isEmpty())
			break;
		else
		{
			node =  s.pop();
			System.out.print(node.data + " ");
			node =  node.r;			
		}
			
		
		
		
	}
	
	
	
	
}
	
	public static void main(String args[])
	{
		int pre[] = new int[]{10, 5, 1, 7, 40, 50};
		
		BSTfromPreOrder tree =  new BSTfromPreOrder();
	
		Node root = tree.construct(pre, pre.length);
		
		System.out.println("Preorder:");
		tree.preOrder(root);
	    System.out.println("\nInorder:");
		tree.inOrder(root);
		
		
		
	}
	
	
	
	
}