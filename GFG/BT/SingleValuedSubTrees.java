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
# Problem Statement	:  single Value SubTrees 
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
				this.l = this.r = null;
				
			}
	}
class Util{
	
	int value = 0;
	
}
	
class SingleValuedSubTrees	

	{
		Node root;
			public boolean singleValueSubTreesUtil(Node node,  Util V)
			{
				if(node== null)
						return true;
				boolean left =  singleValueSubTreesUtil(node.l,  V);
				boolean right =  singleValueSubTreesUtil(node.r, V);
				
				if(left == false|| right == false)
						return false;
					
				if(node.r != null && node.r.data !=node.data)
					return false;
				if(node.l != null && node.l.data != node.data)
					return false;
				
				V.value = V.value + 1;
				
				return true;
			}
			
			public int singleValueSubTrees(Node node)
			{
				
				Util  V = new Util();
				singleValueSubTreesUtil(node, V);
				return V.value ;
				
			}
			
			public static void main(String args[])
				{
					SingleValuedSubTrees	 bt =  new SingleValuedSubTrees();
					bt.root =  new Node(5);
					bt.root.l = new Node(4);
					bt.root.l.l =  new Node(4);
					bt.root.l.r = new Node(4);
					bt.root.r = new Node(5);
					bt.root.r.r = new Node(5);
					
					System.out.println(bt.singleValueSubTrees(bt.root));
					}
	
	
	
	}