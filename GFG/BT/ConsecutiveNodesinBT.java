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
# Problem Statement	:  Find the max consecutive path in bt  
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
				this.l  =  this.r  =null;
				this.data = data;
			}
	
	}
class 	ConsecutiveNodesinBT
	{
		Node root;
	
		public  int maxConsecutivePathNodes(Node node, int prev, int prevLen)
		{
			if(node == null)
				return prevLen;
			int cur  =  node.data;	
		
		if(cur == prev+1)
			{
			
				return Math.max(maxConsecutivePathNodes(node.l, cur, prevLen+1),maxConsecutivePathNodes(node.r, cur, prevLen+1));
				
			}
			
				int curlen = Math.max(maxConsecutivePathNodes(node.l, cur, 1),(maxConsecutivePathNodes(node.r, cur, 1)));
		
		return Math.max(curlen, prevLen);
		}
		
		public static void main(String args[])
			{
			
				ConsecutiveNodesinBT bt =  new ConsecutiveNodesinBT();
				bt.root  =  new Node(10);
    bt.root.l = new Node(11);
    bt.root.r = new Node(9);
    bt.root.l.l = new Node(13);
    bt.root.l.r = new Node(12);
    bt.root.r.l = new Node(13);
    bt.root.r.r = new Node(8);
 
			
			System.out.println(bt.maxConsecutivePathNodes(bt.root, Integer.MIN_VALUE, 1));
			}
	
	}
	