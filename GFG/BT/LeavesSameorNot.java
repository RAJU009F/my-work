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
# Problem Statement	:  All Leaves of two BTs are same or not
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
		
		Node( int data)
			{
				this.data = data;
				this.l = this.r = null;
			}
	}
	
class LeavesSameorNot
		{
			Node root1, root2;
			
			public  boolean sameLeaves(Node node1, Node node2)
			{
				
				Stack<Node> s1 =  new Stack<Node>();
				Stack<Node> s2 =  new Stack<Node>();
				
				s1.push(node1);
				s2.push(node2);
			    int count =0 ;
				while(!s1.empty() || !s2.empty())
				{
					if(s1.empty() || s2.empty())
						return false;
					count = count +1;
					Node t1 =  s1.pop();
					
					while(t1 !=null && (t1.l !=null || t1.r != null))
					{
						if(t1.r != null)
							s1.push(t1.r);
						if(t1.l != null)
							s1.push(t1.l);
						t1 = s1.pop();
						
					}
					
					Node t2 =  s2.pop();
					while(t2 !=null && (t2.l !=null || t2.r != null))
					{
						if(t2.r != null)
							s2.push(t2.r);
						if(t2.l != null)
							s2.push(t2.l);
						t2 = s2.pop();
						
					}
					//System.out.print(count);
					if(t1 !=null && t2 ==null)
							return false;
					if(t1 == null && t2 !=null)
							return false;
					if(t1 !=null &&  t2 !=null && t1.data !=t2.data)	
					{
						//System.out.print(t1.data + " "+ t2.data);
						return false;}
					
					
				}
				
				return  true;
			}
			
			
			public static void main(String args[])
			{
				
			LeavesSameorNot bt =  new LeavesSameorNot();
			bt.root1 = new Node(1);
			bt.root1.l = new Node(2);
			bt.root1.r = new Node(3);
			bt.root1.l.l = new Node(4);
			bt.root1.r.l = new Node(6);
			bt.root1.r.r = new Node(7);
 
			bt.root2 = new Node(0);
			bt.root2.l = new Node(1);
			bt.root2.r = new Node(5);
			bt.root2.l.r = new Node(4);
			bt.root2.r.l = new Node(6);
			bt.root2.r.r = new Node(7);
			
			System.out.println(bt.sameLeaves(bt.root1, bt.root2));
			
			}
		
		}