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
# Problem Statement	:  In Order and post order 
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
				this.l =  this.r =  null;
				this.data = data;
			}
	
	
	}
	
class Util	
{
 int	index =  0;
}	
	
class InPostBTBuild
		{
			Node root;
			
			public  int search(int in[], int l, int r, int key)
			{
				for(int i=l; i<=r; i++)
					if(in[i]==key)
						return i;
				return -1;	
				
				
			}
			
			public Node buildTreeUtil(int in[], int post[],  int l,  int r,  Util postIndex)
				{
					if(l>r || postIndex.index<0)
						return null;
						
					int index =  postIndex.index;

					Node  node =  new Node(post[index]);
					postIndex.index--;
					if(l==r)
						return node;
						
					{
					int i =  search(in, l, r,  node.data);
					
					node.r  = buildTreeUtil(in, post, i+1, r, postIndex);
					node.l = buildTreeUtil(in, post, l, i-1, postIndex);
					
					}	
						
				
				return node;
				
				}
			public Node buildTree(int in[], int post[])
				{
					Util  postIndex =  new Util();
					postIndex.index = post.length-1;
					int inL = 0;
					int inR = in.length-1;
					
					return buildTreeUtil(in, post, inL, inR, postIndex);	
				
				}
			public void  inorder(Node node)
				{
					if(node == null)
						return;
					inorder(node.l);
					System.out.print(node.data+" ");
					inorder(node.r);
				
				
				}
			public void postorder(Node node)
			{
				if(node==null)
					return;
					
					postorder(node.l);
					postorder(node.r);
					System.out.print(node.data+" ");
				
				
			}
			public static void main(String args[])
				{
					
					InPostBTBuild bt =  new InPostBTBuild();
					int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
					int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
					bt.root =  bt.buildTree(in, post);

					
					bt.inorder(bt.root);
					bt.postorder(bt.root);
					
				}
		
		
		}