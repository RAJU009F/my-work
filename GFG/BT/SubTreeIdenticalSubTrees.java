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
# Problem Statement	:  Largest sub tree with identical left and right sub trees
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
				this.data =data;
				this.l =  null;
				this.r =  null;
				
			
			}
	}
	
class Util	
{
	Node maxNode = null;
	int maxSize = 0;
	
	
}
class SubTreeIdenticalSubTrees
		{
			Node root;
			
			public int largeSubTreeNodeUtil(Node node, String str, Util v)
			{
				if(node == null)
					return 0;
				String left = "";
				String right =  "";
				
				int l =  largeSubTreeNodeUtil( node.l, left, v );
				int r =  largeSubTreeNodeUtil( node.r, right, v);
				
				int size = l+r+1;
					if(left.equals(right) && v.maxSize<size)
					{
						v.maxSize = size;
						v.maxNode = node;
						System.out.println(left +" "+ right);
					}
					
					str = str+"|"+left+"|";
					str = str+"|"+String.valueOf(node.data)+"|";
					str = str+"|"+right+"|";
					
					System.out.println(str );
					return size;
						
				
				
			}
			
			public Node largeSubTreeNode(Node node)
			{
				if(node == null)
						return null;
				Util v =  new Util();
				String str = "";
				largeSubTreeNodeUtil(node, str, v);
				
				return v.maxNode;
			}
			
			public void printBT(Node node, int space)
			{
				if(node == null)
					return;
				space +=10;
				printBT(node.l, space);
				System.out.println();
				for(int i=0; i<space; i++)
					System.out.print(" ");
				System.out.println(node.data+" ");
				printBT(node.r, space);
				
				
				
			}
			
			public static void main(String args[])
				{
					SubTreeIdenticalSubTrees bt =  new SubTreeIdenticalSubTrees();
					bt.root = new Node(50);
					bt.root.l = new Node(10);
					bt.root.r = new Node(60);
					bt.root.l.l = new Node(5);
					bt.root.l.r = new Node(20);
					bt.root.r.l = new Node(70);
					bt.root.r.l.l = new Node(65);
					bt.root.r.l.r = new Node(80);
					bt.root.r.r = new Node(70);
					bt.root.r.r.l = new Node(65);
					bt.root.r.r.r = new Node(80);
					Node largeNode =bt.largeSubTreeNode(bt.root);
					bt.printBT(largeNode, 10);
					
				}
		
		
		}