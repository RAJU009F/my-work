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
# Problem Statement	: Construct FULL  Binary tree from Pre order and post order treversal
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
	
	Node(int data)
	{
		this.data = data;
		this.l = null;
		this.r =  null;
	}
	
}

class Index 
{
	
	int index  = 0;
}


class FullBinaryTreefromPrePost
	{
		Node root;
		
		public Node makeFullBTUtil(int pre[], Index in, int post[],  int l, int r,  int size, Node node)
		{
			int index =  in.index;
			if(index >= size || l>r)
				return null;
			node =  new Node(pre[index]);
				
			if(l==r)
					return node;
				int i;
				++(in.index);
			for(i=l; i<=r; i++)
			{
				if(pre[in.index]==post[i])
					break;
				
			}
		
			if(i<=r)
			{
			node.l =  makeFullBTUtil(pre, in, post, l, i, size, node.l);
			node.r =  makeFullBTUtil(pre, in, post, i+1, r, size, node.r);
			}
			return node;


		
		}
		
		
		public Node makeFullBT(int pre[],  Index in, int post[],  Node node)
		{
			return makeFullBTUtil(pre, in, post, 0, post.length-1, post.length, node);
			
		}
		
		public void  preOrder(Node node)
		{
			if(node == null)
				return;
			
			System.out.print(node.data+" ");
			preOrder(node.l);
			preOrder(node.r);
			
		}
		
		public static void main(String args[])
		{
			int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
			int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
			FullBinaryTreefromPrePost bt =  new FullBinaryTreefromPrePost();
			Index in = new Index();
			bt.root =  bt.makeFullBT(pre, in, post, bt.root );
			
			bt.preOrder(bt.root);
		}
	
	}
 	