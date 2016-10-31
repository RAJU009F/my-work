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
# Problem Statement	:  check the covered and uncoveed sum in Tree
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
				this.l =  this.r = null;
				this.data = data;
			}
	}
	
class checkCoveredUnCoveredTreeUT
		{
			Node root;
			
			public int sumTree(Node node)
			{
				if(node == null)
						return 0;
				return sumTree(node.l)+node.data+sumTree(node.r);	
				
				
			}
			
			public int uncoveredSumLeft(Node node)	
			{
				if(node == null)
						return 0;
				if(node.l != null)
						return node.data+uncoveredSumLeft(node.l);
				else if(node.r != null)
						return node.data + uncoveredSumLeft(node.r);
				else 
						return 0;
				
			}
			
			public int uncoveredSumRight(Node node)	
			{
				if(node == null)
						return 0;
				if(node.r != null)
						return node.data+uncoveredSumRight(node.r);
				else if(node.l != null)
						return node.data + uncoveredSumRight(node.l);
				else 
						return 0;
				
			}
			
			public boolean isTreeCovered(Node node)
			{
				if(node == null)
						return true;
				
				int sum =  sumTree(node);
				int uncoveredSum =  node.data+uncoveredSumLeft(node.l) + uncoveredSumRight(node.r);
				System.out.println(sum +" "+uncoveredSum);
				return (sum-uncoveredSum == uncoveredSum);
			}
				
			
			public static void main(String args[])
				{
				
				checkCoveredUnCoveredTreeUT bt =  new checkCoveredUnCoveredTreeUT();
				bt.root = new Node(8);
				bt.root.l = new Node(3);
				bt.root.l.l = new Node(1);
				bt.root.l.r =  new Node(6);
				bt.root.l.r.l =  new Node(4);
				bt.root.l.r.r =  new Node(7);
				bt.root.r =  new Node(10);
				bt.root.r.l =  new Node(32);
				bt.root.r.r =  new Node(14);
				bt.root.r.r.l =  new Node(13);
				
				System.out.println(bt.isTreeCovered(bt.root));
				
 				
				}
		
		}