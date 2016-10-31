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
# Problem Statement	:  Evaluate the expression
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
		char data;
		Node l;
		Node r;
		
		Node(char data)
			{
				this.l= this.r  =null;
				this.data = data;
			
			
			}
	}
	
class EvaluateExpressionTree
		{
			Node root;
			
			public int evaluateTree(Node node)
			{
				if(node == null)
					return 0;
				if(node.l ==null && node.r==null)
					return Integer.valueOf(node.data);
				int l  =  evaluateTree(node.l);
				int r  =  evaluateTree(node.r);
				if(node.data=='+')
					return l+r;
				if(node.data == '-')
					return l-r;
				if(node.data == '*')
					return l*r;
			 else
					return l/r; 
				
			}
			
			public static void main(String args[])
				{
				
				EvaluateExpressionTree bt  =  new EvaluateExpressionTree();
				bt.root =  new Node('+');
				bt.root.l =  new Node('*');
				bt.root.r = new Node('-');
				bt.root.l.l =  new Node('5');
				bt.root.l.r = new Node('4');
				bt.root.r.l = new Node('9');
				bt.root.r.r  =  new Node('/');
				bt.root.r.r.l = new Node('8');
				bt.root.r.r.r = new Node('2');
				
				System.out.println(bt.evaluateTree(bt.root));
				}
		
		
		
		}