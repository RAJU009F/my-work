import java.io.*;
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
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	:  reverse the alterantive levles
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
			this.l = null;
			this.r = null;
			this.data = data;
		}
	}

	class ReverseAlternateLevles
		{
			Node root;
			
			public  void reverseAlternateLevelesUtil(Node node1, Node node2, int level)
			{
				if(node1 == null ||  node2 == null)
						return;
				if(level%2==0)
				{
					int temp = node1.data;
					node1.data = node2.data;
					node2.data =  temp;
					
				}
				
				reverseAlternateLevelesUtil(node1.l, node2.r, level+1);
				reverseAlternateLevelesUtil(node1.r, node1.l, level+1);
				
				
			}
			
			public void reverseAlternateLeveles(Node node)
			{
				if(node==null)
				return;
			reverseAlternateLevelesUtil(node.l, node.r, 0);
				
				
				
			}
			public void inorder(Node node)
			{
				
				if(node==null)
						return;
					
				inorder(node.l);
					System.out.print(node.data+" ");
				inorder(node.r);	
				
				
			}
			
			
			public static void main(String args[])
			{
			
			 ReverseAlternateLevles bt =  new ReverseAlternateLevles();
				bt.root =  new Node(1);
				bt.root.l = new Node(2);
				bt.root.r = new Node(3);
				bt.root.l.l = new Node(4);
				bt.root.l.r = new Node(5);
				bt.root.r.l =  new Node(6);
				bt.root.r.r = new Node(7);
				bt.inorder(bt.root);
				bt.reverseAlternateLeveles(bt.root);
				System.out.println();
				bt.inorder(bt.root);
			}
		
		
		}