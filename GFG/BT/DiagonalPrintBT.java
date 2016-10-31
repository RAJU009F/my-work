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
				this.l = this.r= null;
			}
	
	}

class DiagonalPrintBT
		{
			
				Node root;
			// public void digonalPrintUtil(Node node, int d,  HashMap<Integer, ArrayList> hm)	
			// {
				// if(node == null)
						// return;
				// digonalPrintUtil(node.l, d+1, hm);
				// digonalPrintUtil(node.r, d, hm);
				// if(hm.containsKey(d))
				// {	ArrayList arr = hm.get(d);
					// arr.add(node.data);
					// hm.put(d, arr);
			// }
				// else
				// {
					// ArrayList arr = new ArrayList();
					// arr.add(node.data);
					// hm.put(d, arr);
				// }
				
				
			// }
			
			// public void digonalPrint(Node node)
			// {
				// if(node == null)
					// return;
				
				// Map<Integer, ArrayList> hm =  new HashMap<Integer, ArrayList>();
				// digonalPrintUtil(node, 0, arr);
				
				// Iterator it = hm.entrySet().iterator();
				// while(it.hasNext())
				// {
					// Map.Entry<Integer, ArrayList> e =  it.next();
					
					// Iterator arr = it.next().getValue().iterator();
					// while(arr.hasNext())
					// {
						// System.out.print(arr.next()+" ");
						 // ll.removeFirst(0);
					// }
					// System.out.println();
				// }
				
				
				
			// }
			
			public void diagonalPrint(Node node)
			{
				if(node == null)
						return;
					
				Node head =  node;
				Node tail  =  node;
				Node temp = null;
				
				while(tail.r !=null)
					tail = tail.r;
				
				while(head !=null)
				{
					Node cur = head;
					temp  = tail;
					while(cur !=temp)
					{
						System.out.print(cur.data+" " );
						Node curN = cur.l;
						
						while(curN !=null)
						{
							temp.r = curN;
							curN = curN.r;
							temp = temp.r;
						}
						
						cur = cur.r;
						
					}
					tail = temp;
					System.out.println(cur.data);
					
					head = cur.r;
					
				}
				
				
				
			}
			
			public static void main(String args[])
				{
					DiagonalPrintBT bt =  new DiagonalPrintBT();
					
						bt.root =  new Node(1);
					
						bt.root.l =  new Node(2);
						bt.root.r = new Node(3);
					
						bt.root.l.l =  new Node(4);
						bt.root.l.r = new Node(5);
					
						bt.root.r.l =  new Node(6);
						bt.root.r.r = new Node(7);
					
						bt.root.l.l.l =  new Node(8);
						bt.root.l.l.r = new Node(9);
						
						bt.root.l.r.l =  new Node(10);
						bt.root.l.r.r = new Node(11);
						bt.diagonalPrint(bt.root);
						
				}
		
		
		}