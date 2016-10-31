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
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/BT
# Problem Statement	: find the height of the tree given their indexs
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
		this.data  =  data;
		this.l = this.r =  null;
	}
}


class QNode
{
	Node node;
	int hd;
	
	QNode(Node node, int hd)
	{
		this.node =  node;
		this.hd =  hd;
		
	}
	
}

class TreeTopView
{
	Node root;
	
	public void printTopView(Node node)
	{
		if(node == null)
			return;
		HashSet<Integer> hs =  new HashSet<Integer>();
		Queue<QNode> q =  new LinkedList<QNode>();
		q.add(new QNode(node, 0));
		
		
		while(!q.isEmpty())
		{
			QNode qnode =  q.peek();
			q.poll();
			
			if(!hs.contains(qnode.hd))
			{
				hs.add(qnode.hd);
				System.out.print(qnode.node.data+" " );
				
				
			}
			
			if(qnode.node.l !=null)
				q.add(new QNode(qnode.node.l, qnode.hd-1));
			if(qnode.node.r !=null)
				q.add(new QNode(qnode.node.r , qnode.hd+1));
		}
		
		
		
	}
	
	public static void main(String args[])
	{
		TreeTopView bt = new TreeTopView();
		bt.root = new Node(1);
		bt.root.l =  new Node(2);
		bt.root.r =  new Node(3);
		bt.root.l.l =  new Node(4);
		bt.root.l.r =  new Node(5);
		bt.root.r.r = new Node(7);
		bt.root.r.l = new Node(6);
		
		bt.root.l.r =  new Node(9);
		bt.root.l.r.r = new Node(10);
		bt.root.l.r.r.r = new Node(11);
		bt.root.l.r.r.r.r = new Node(12);
		bt.root.l.r.r.r.r.r =  new Node(13);
		bt.root.l.r.r.r.r.r.r =  new Node(14);
		
		bt.printTopView(bt.root);
		
	}
	
	
}