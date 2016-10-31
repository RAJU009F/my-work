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
# Problem Statement	: Complete Binary tree or not using recursion
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
			this.l = null;
			this.r = null;
		}
}
	
class CompleteBTorNot
		{
			Node root;
			
		public int countNodes(Node node)
			{
				if(node == null)
					return 0;
				return 1+ countNodes(node.l)+countNodes(node.r);	
			
			}
			
		public boolean isCompleteTreeUtil(Node node , int index, int numofNodes)
			{
				if(node == null)
					return true;
				if( index>= numofNodes)
					return false;
		
				return isCompleteTreeUtil(node.l, 2*index+1, numofNodes) && isCompleteTreeUtil(node.r, 2*index+2, numofNodes);
			
			
			}
		public boolean isCompleteTree(Node node)
			{
				if(node == null)
					return true;
					
				int numofNodes = countNodes(node);	
				
				return isCompleteTreeUtil(node, 0,  numofNodes);
			
			}
			
		public static void main(String args[])
			{
				CompleteBTorNot bt =  new CompleteBTorNot();
				bt. root =  new Node(1);
				bt.root.l = new Node(2);
				bt.root.r = new Node(3);
				bt.root.l.l =  new Node(4);
				bt.root.l.r =  new Node(5);
				bt.root.r.r = new Node(6);
				System.out.println(bt.isCompleteTree(bt.root));
				bt.root.r.l= new Node(7);
				System.out.println(bt.isCompleteTree(bt.root));
			}
		
		}