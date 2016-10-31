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
# Problem Statement	: Max sum path between two leaf nodes
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
				this.r =  null;
			
			}
	
	
	}
class SUM
{
	int sum = 0;
	
}
	
class MaxSumPathBetweenLeaves
		{
			Node root;
			
			public int maxSumUtil(Node node, SUM sum)
			{
				if(node == null )
					return 0;
				if(node.l == null && node.r == null)
					return  node.data;
				int ls =  maxSumUtil(node.l, sum);
				int rs =  maxSumUtil(node.r, sum);
				
				if(node.l != null  && node.r != null)
				{
					sum.sum = Math.max(sum.sum, ls+rs+node.data);
					
					return Math.max(ls, rs)+node.data;
					
				}
				
				
				return node.l==null?rs+node.data:ls+node.data;
			}
			public int maxSum(Node node)
			{
				
				if(node == null)
					return 0;
				SUM sum =  new SUM();
				 maxSumUtil(node, sum);
				 return sum.sum;
			}
			public static void main(String args[])
			{
				MaxSumPathBetweenLeaves bt = new MaxSumPathBetweenLeaves();
				// bt.root =  new Node(1);
				// bt.root.l = new Node(2);
				// bt.root.r = new Node(3);
				// bt.root.l.l = new Node(4);
				// bt.root.l.r = new Node(5);
				// bt.root.r.l =  new Node(6);
				// bt.root.r.r = new Node(7);
				
				bt.root = new Node(-15);
    bt.root.l = new Node(5);
    bt.root.r = new Node(6);
    bt.root.l.l = new Node(-8);
    bt.root.l.r = new Node(1);
    bt.root.l.l.l = new Node(2);
    bt.root.l.l.r = new Node(6);
    bt.root.r.l = new Node(3);
    bt.root.r.r = new Node(9);
    bt.root.r.r.r= new Node(0);
    bt.root.r.r.r.l= new Node(4);
    bt.root.r.r.r.r= new Node(-1);
    bt.root.r.r.r.r.l= new Node(10);
				
				
				System.out.println(bt.maxSum(bt.root));
			}
		}
	