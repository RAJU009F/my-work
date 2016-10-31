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
# Problem Statement	: ROOT TO LEAF PATH WITH GIVEN SUM EXISTS
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
		this.l = null;
		this.r =  null;
		
	}
	
}

class RootLeafPathSum
{
	
	Node root;
	
	public boolean hasPathSum(Node node, int sum)
	{
			if(node == null)
				return sum==0;
			sum =  sum - node.data;
			return (sum == 0 && node.l == null && node.r==null) || hasPathSum(node.l, sum) ||hasPathSum(node.r, sum);
		
	}
	public static void main(String args[])
	{
		RootLeafPathSum bt =  new RootLeafPathSum();
		bt.root  =  new Node(10);
		bt.root.l = new Node(8);
		bt.root.l.l =  new Node(3);
		bt.root.l.r  =  new Node(5);
		
		bt.root.r =  new Node(2);
		bt.root.r.l =  new Node(2);
		
		System.out.println(bt.hasPathSum(bt.root,23));
		
	}
	
	
	
}