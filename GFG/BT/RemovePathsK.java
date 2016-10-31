import java.lang.*;
import java.util.*;

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
# Problem Statement	: Remove paths of length <K
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
		int data;
		Node l;
		Node r;
		
		Node( int data)
			{
				this.data = data;
				this.l = this.r =  null;
			}
	
	}

	class RemovePathsK
		{
			Node root;
			
			public void removePathLessKLength(Node node)
			{
				if(node == null)
					return ;
				
				
			}
			
			public void postorder(Node node)
			{
				if(node == null)
					return;
				postorder(node.l);
				postorder(node.r);
				System.out.print(node.data+" ");
				
				
			}
			
				public Node removePathLessKLength(Node node, int k,  int level)
				{
					if(node == null)
						return null;
					
					node.l = removePathLessKLength(node.l, k, level+1);
					node.r = removePathLessKLength(node.r, k,  level+1);
					
					if(node.l == null && node.r== null && k>level)
						return null;
					
					return root;
					
					
				}
			
			public static void main(String args[])
				{
				
					RemovePathsK bt =  new RemovePathsK();
					
					bt.root= new Node(1);
					bt.root.l = new Node(2);
					bt.root.r = new Node(3);
					bt.root.l.l = new Node(4);
					bt.root.l.r = new Node(5);
					bt.root.l.l.l = new Node(7);
					bt.root.r.r = new Node(6);
					bt.root.r.r.l = new Node(8);
					bt.postorder(bt.root);
					bt.root=bt.removePathLessKLength(bt.root,  4, 1);
					System.out.println();
					bt.postorder(bt.root);			
								
				}
			
		
		
		}