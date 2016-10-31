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
# Problem Statement	:  
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
	
class Util
{
	Node parent;

	int level;
	
	
	
}	
	
	class AreCousins
	{
		Node root;
		
		
		public  void getLevelandParent(Node h, Node target,  int level,Util u)
		{
			if(h == null)
				return;
			if(h.l==target || h.r==target)
			{
				u.level = level+1;
				u.parent = h;
			}
			
			getLevelandParent(h.l, target, level+1, u );
			getLevelandParent(h.r, target, level+1, u);
			
		}
		
		public boolean areCousins(Node h, Node node1, Node node2)
		{
			if(h==null)
				return false;
			
			Util u =  new Util();
			
			getLevelandParent(h, node1, 0,u);
			Node parent = u.parent;
			int level = u.level;
			
			Util v=  new Util();
			getLevelandParent(h, node1, 0, v);
			
			System.out.println(parent.data + " "+ level);
			System.out.println(v.parent.data + " "+ v.level);
			return (parent==v.parent && v.level==level);
			
		}
		
		public static void main(String args[])
		{
		
			AreCousins bt =  new AreCousins();
			bt.root =  new Node(1);
				bt.root.l = new Node(2);
				bt.root.r = new Node(3);
				bt.root.l.l = new Node(4);
				bt.root.l.r = new Node(5);
				bt.root.r.l =  new Node(6);
				bt.root.r.r = new Node(7);
				
				System.out.println(bt.areCousins(bt.root, bt.root.r.r , bt.root.l.l));	
				System.out.println(bt.areCousins(bt.root, bt.root.r.r , bt.root.l));	
		
			
			
		}
	
	
	
	}