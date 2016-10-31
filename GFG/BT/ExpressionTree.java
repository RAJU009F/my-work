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
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	: Expression tree
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
		char data;
		
		Node(char data)
		{
			this.data = data;
			
			this.l = null;
			this.r = null;
		
		
		}
	
	}
	
	
	
class ExpressionTree
		{
			Node root;
			
			
			public boolean isOperator(char op)
			{
				return (op == '/' || op == '%' || op == '*' || op == '+' || op == '-' || op == '^');
			
			}
			public Node createExpressionTree(char exp[])
				{
					int len = exp.length;
					Stack<Node> s =  new Stack<Node>();
					Node node ;
					for(int i=0; i<len; i++)
					{
						if(!isOperator(exp[i]))
							{
							 node =  new Node(exp[i]);
							
							}else
							{
							 node = new Node(exp[i]);
								Node r =  s.pop();
								// s.poll();
								Node l = s.pop();
								node.l = l;
								node.r = r;
								
							}
					
						s.push(node);
					}
				
				
				node =  s.pop();
		
				return node;
				
				}
			public void inorder(Node node)
			{
				if(node == null)
						return;
				inorder(node.l);
				System.out.print(node.data+" ");
				inorder(node.r);
				
				
			}
			
			public static void main(String args[])
				{
				ExpressionTree bt =  new ExpressionTree();
					char str[] = "ab+cf*g*-".toCharArray();
				bt.root = bt.createExpressionTree(str);	
				
				bt.inorder(bt.root);
				
				}
		
		
		
		}