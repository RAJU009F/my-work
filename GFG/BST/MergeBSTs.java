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
# Problem Statement	: Java: Merge two BSTs 
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


class MergeBSTs

{

static Node root ;


public void inorder(Node root)
{
	if(root != null)
	{
		inorder(root.l);
		System.out.print(root.data + " ");
		inorder(root.r);
		
	}
	
	
}


public void mergeTrees(Node root1, Node root2)
{
	if(root1 == null && root2 == null)
		return;
	if(root1 == null)
	{
		inorder(root2);
		return;
	}
	if(root2 == null)
	{
		inorder(root1);
		return;
	}
	
	Stack<Node> s1 =  new Stack<Node>();
	Stack<Node> s2 = new Stack<Node>();
	
	while(root1 !=null || root2 != null || s1.isEmpty() == false || s2.isEmpty()==false )
	{
		if( root1 == null || root2 == null)
		{
		if(root1 != null)
		{
			s1.push(root1);
			root1 = root1.l;
			
			
		}
		
		if(root2 != null)
		{
			s2.push(root2);
			root2 = root2.l;
		}
		
		}
		else{		
			if(root1 == null)
			{				
		     while(s2.isEmpty() == false)
				{
					root2 = s2.pop();
					root2.l = null;
					inorder(root2);				
				}				
				return;
			}

			if( root2 == null)
			{
				while(s1.isEmpty() == false)
				{
					root1 = s1.pop();
					root1.l = null;
					inorder(root1);
					
				}				
				return;
				
			}
		
			
			root1  =  s1.pop();
			root2  =   s2.pop();
			
			if(root1.data> root2.data)
			{
				System.out.print(root2.data+" ");
				root2 = root2.r;
				s1.push(root1);
				root1 = null;
			}else
			{
				System.out.print(root1.data+" ");
				root1 = root1.r;
				s2.push(root2);
				root2 = null;
				
			}
			
			
		
		
		
		}
		
		
		
		
		
		
		
		
	}
	
	
}

public void mergeTrees1(Node root1, Node root2)
{
	if(root1 == null && root2 == null)
			return;
	
	if(root1 == null)
	{
		inorder(root2);
		return;
	}
	
	if(root2 == null)
	{
		inorder(root1);
		return;	
	}
	
	Stack<Node> s1 =  new Stack<Node>();
	Stack<Node> s2 = new Stack<Node>();
	
	boolean flag1= true;
	boolean flag2 = true;
	
	while( flag1 || flag2 || s1.isEmpty() == false || s2.isEmpty()==false)
	{
		while(flag1)
		{
			if(root1 != null)
			{
				s1.push(root1);
				root1 =  root1.l;		
			}else
			{
				if(s1.isEmpty())
					flag1 = false;
				else
				{
					root1 = s1.pop();
					flag1 = false;
				}	
			}			
		}
		
		while(flag2)
		{
			if(root2 != null)
			{
				s1.push(root2);
				root2 =  root2.l;		
			}else
			{
				if(s2.isEmpty())
					flag2 = false;
				else
				{
					root2 = s2.pop();
					flag2 = false;
				}	
			}			
		}
		if(root1 == null || root2 == null)
		{		
			if(root1 == null && s1.isEmpty())
			{
				
				s2.push(root2);
				while(s2.isEmpty() == false)
				{
					root2 = s2.pop();
					root2.l = null;
					inorder(root2);
					
				}
				return ;
			}
			
			if(root2 == null && s2.isEmpty())
				{
					
					s1.push(root1);
					while(s1.isEmpty() == false)
					{
						root1 = s1.pop();
						root1.l = null;
						inorder(root1);
						
					}
					return ;
				}
		}else
		{
			if(root1.data == root2.data)
			{
				System.out.print(root1.data +" "+root2.data);
				root1 = root1.r;
				root2 = root2.r;
				flag1 = true;
				flag2 = true;
			}else if(root1.data > root2.data)
			{
				System.out.print(root2.data+" ");
				flag2 = true;
				root2 = root2.r;
			}else
			{
				System.out.print(root1.data+" ");
				flag1 = true;
				root1 = root1.r;
			}
			
			
			
			
		}
		
	}
	
	
	
}

public static void main(String args[])
{
	MergeBSTs tree =  new MergeBSTs();
	
	Node root1 = new Node(10);
	root1.l = new Node(4);
	root1.r = new Node(12);
		
	Node root2 =  new Node(32);
	root2.l = new Node(3);
	root2.r =  new Node(45);
	
	tree.mergeTrees(root1, root2);
	
	
}

}