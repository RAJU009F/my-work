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
# Problem Statement	:  
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
		Node( int data)
			{
				this.data = data;
				this.l = this.r  = null;
			}
	}
	
class Util
{
	int d = 0;
	
}
class MaxAncestorDiff
		{
			Node root;
			
			public int maxDiffUtil(Node node, Util V)
			{
				if(node==null)
					return Integer.MAX_VALUE;
				if(node.l == null && node.r == null)
					return node.data;
				int v =  Math.min(maxDiffUtil(node.l, V), maxDiffUtil(node.r, V));
				
				V.d = Math.max(V.d, node.data-v);
				
				return v<node.data?v:node.data;
				
				
			}
			
			public int maxDiff(Node node)
			{
					if(node == null)
						return 0;
					Util V =  new Util();
					maxDiffUtil(node, V);	
				
				return V.d;
			}
			
			public static void main(String args[])
				{
					MaxAncestorDiff bt =  new MaxAncestorDiff();
					bt.root =  new Node(8);
					bt.root.l = new Node(3);
					bt.root.l.l = new Node(1);
					bt.root.l.r =  new Node(6);
					bt.root.l.r.r = new Node(7);
					bt.root.r = new Node(10);
					bt.root.r.r = new Node(14);
					bt.root.r.r.l = new Node(13);
					
					System.out.println(bt.maxDiff(bt.root));	
				}
		
		}
	