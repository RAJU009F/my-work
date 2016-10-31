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
# Problem Statement	:  BST from Post Order Traversal
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
		this.l = l;
		this.r = r;
	}

}

class Util
{
	int index = 0;
}

class BSTfromPostOrder
	{
		Node root;
		
		public Node createTreeUtil(int post[], Util v, int key, int min, int max)
		{
			if(v.index<0)
				return null;
			
				Node node = null;
			if( key>min && key<max)
				
			{
				 node = new Node(key);

				v.index -= 1;
				if(v.index>=0)
				{
					node.r = createTreeUtil(post, v, post[v.index], key, max);
					node.l = createTreeUtil(post, v, post[v.index], min, key);
					//root.l = createTreeUtil(post, Util, post[v.index], min, key);
					
				}
			}
		
			
		return node;
		
		
		}
		
		public Node createTree(int post[])
		{
		
			Util v =  new Util();
			v.index =  post.length-1;
			return createTreeUtil(post, v, post[v.index], Integer.MIN_VALUE, Integer.MAX_VALUE );
		
		
		}
		
		public void postOrder(Node node)
		{
			if(node == null)
				return;
			postOrder(node.l);
			postOrder(node.r);
			System.out.print(node.data+" ");
			
		}
		
		public static void main(String args[])
		{
		int post[] = {1,7, 9,5,30,50,40,10};
		BSTfromPostOrder bt = new  BSTfromPostOrder();
			bt.root = bt.createTree(post);
			
			bt.postOrder(bt.root);
		
		}
	
	
	}