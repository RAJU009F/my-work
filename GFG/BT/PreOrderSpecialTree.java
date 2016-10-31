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
# Problem Statement	:  construct BT from Pre Order Travesal 
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
				this.r = null;
			}
	}

class Index
{
	int index=0;
	
}	
	
class PreOrderSpecialTree
{
	Node root;
	//static int i=0;
	Node createTree(int pre[],  char preLN[],  Index in,  int n, Node node)
	{
		int index =  in.index;
		if(index==n)
			return null;
		
		node = new Node(pre[index]);
		//System.out.print(node.data+" ");
		in.index++;
		if(preLN[index] == 'N')
		{
			
			node.l =  createTree(pre, preLN, in,  n, node.l);
			node.r =  createTree(pre, preLN, in,  n, node.r);
		}
		
		return node;
		
		
	}
	
	public void preOrder(Node node)
	{
		if(node == null)
			return;
		System.out.print(node.data+" ");
		preOrder(node.l);
		preOrder(node.r);
		
		
	}
	
	public static void main(String args[])
		{
			PreOrderSpecialTree bt =  new PreOrderSpecialTree();
	
			int pre[] = {10, 30, 20, 5, 15};
			char preLN[] = {'N', 'N', 'L', 'L', 'L'};
			Index in =  new Index();
			
			bt.root = bt.createTree(pre, preLN, in, pre.length, bt.root);
			bt.preOrder(bt.root);
		
		}



}	