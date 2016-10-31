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
# Problem Statement	: check the bt is foldable or not 
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
		this.l =  null;
		this.r = null;
		
	}
}

class IsFoldable
{
	Node head;
	
	public boolean areMirrors(Node node1 ,  Node node2)
	{
		if(node1==null && node2 == null)
			return true;
		if(node1 == null ||  node2 == null)
				return false;
			
		return areMirrors(node1.l, node2.r) && areMirrors(node1.r, node2.l);	
		
	}
	public boolean isFoldable(Node root)
	{
		if(root == null)
			return true;
		
		return areMirrors(root.l, root.r);
		
	}
	public static void main(String args[])
	{
		IsFoldable bt =  new IsFoldable();
		
		bt.head = new Node(10);
		bt.head.l =  new Node(7);
		bt.head.r =  new Node(15);
		bt.head.l.r =  new Node(9);
		bt.head.r.l =  new Node(11);
		bt.head.l.r.l =  new Node(19);
		//bt.head.r.l.r =  new Node(111);
		
		System.out.println(bt.isFoldable(bt.head));
	}
	
}