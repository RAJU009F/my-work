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
# Problem Statement	:  print Diagonal print of BT
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
				this.data = data;
				this.l = this.r = null;
			}
	
	
	}
class BTSpiralLevelDLL
		{
			Node root;
			
			public Node spiralDLL(Node node)
			{
				if(node==null)
						return null;
				if(node.l ==null && node.r == null)	
					return node;
				Node list = node;
				Node tail = node;
				Queue<Node> q = new LinkedList<Node>();
				if(node.l!=null)
					q.add(node.l);
				if (node.r!=null)
					q.add(node.r);
				int level =1;
				while(!q.isEmpty())
				{
					
					int n  =  q.size();
					
					Node temp = null;
						Node h = null;	
						
					
					while(n>0)
					{
						node =  q.peek();
						q.poll();
						//System.out.print(node.data);
						if(node.l !=null)
							q.add(node.l);
						if(node.r !=null)
							q.add(node.r);
						if((level&1) == 1)
						{
							if(temp == null)
							{
								temp = node;
								h = node;
							}else
							{
								node.r = temp;
								temp.l = node;
								temp = temp.l;
								
							}	
						}else
						{	
							tail.r = node;
							node.l = tail;
							tail = node;	
						}
						
						
						n--;
					}
					
					if((level&1)==1 && temp !=null)
					{
						tail.r = temp;
						temp.l = tail;
						tail = h;
				
				
					}
					
					
					level++;
				}
				
				
				return list;
			}
			
			public void printList(Node list)
			{
				if(list == null)
					return;
				while(list !=null)
				{
					System.out.print(list.data+" ");
					list = list.r;
				}
			}
			
			
			public static void main(String args[])
			{
			
			BTSpiralLevelDLL bt =  new BTSpiralLevelDLL();
			bt.root = new Node(1);
			bt.root.l = new Node(2);
			bt.root.r = new Node(3);
			bt.root.l.l = new Node(4);
			bt.root.l.r = new Node(5);
			bt.root.r.l = new Node(6);
			bt.root.r.r = new Node(7);
			
			
			bt.root.l.l.l  = new Node(8);
			bt.root.l.l.r  = new Node(9);
			bt.root.l.r.l  = new Node(10);
			bt.root.l.r.r  = new Node(11);
			bt.root.r.l.l  = new Node(12);
			bt.root.r.l.r  = new Node(13);
			bt.root.r.r.l  = new Node(14);
			bt.root.r.r.r  = new Node(15);
			
			Node list = bt.spiralDLL(bt.root);
			bt.printList(list);

		}
		
		
		}
	