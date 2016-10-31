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
# Problem Statement	: Diagonal Sum of a Tree
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


class DiagonalSum
{
	Node root;
	
	public void printDiagonalSum(Node node)
	{
		
		if(node == null)
			return;
		
		Node head = node;
		Node tail  =  node;
		Node cur = null;
		Node temp = null;
		// Node prev = null;
		
		int sum=0;
		temp  =  head;
		
		while(temp.r != null)
		{
			temp =  temp.r;
			
		}
		
		tail = temp;
		
		while(head != null)
		{
			cur =  head;
			sum = 0;
			temp =  tail;
			while(cur != tail)
			{				
				sum +=cur.data;				
				Node curN =  cur.l;
				
				while(curN !=null)
				{	
					temp.r =  curN;
					temp =  temp.r;	
					curN =  curN.r;
				}	
				
				cur =  cur.r;
				
			}
			
			tail =  temp;
			sum =  sum + cur.data;
			System.out.println(sum);
			head =  cur.r;
			
			
		}
		
			
		
		
		
		
		
	}
	
	public static void main(String args[])
	{
		DiagonalSum bt = new DiagonalSum();
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
		
		bt.printDiagonalSum(bt.root);
		
		DiagonalSum bt1 = new DiagonalSum();
		 bt1.root = new Node(1);
        bt1.root.l = new Node(2);
       bt1.root.r = new Node(3);
        bt1.root.l.l = new Node(9);
      bt1.root.l.r = new Node(6);
       bt1.root.r.l = new Node(4);
       bt1.root.r.r = new Node(5);
       bt1.root.r.l.l = new Node(12);
       bt1.root.r.l.r = new Node(7);
      bt1.root.l.r.l = new Node(11);
        bt1.root.l.l.r = new Node(10);
		
		bt1.printDiagonalSum(bt1.root);
	}
	
	
}