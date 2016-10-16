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
# Topic or Type 	: GFG/LinkedList
# Problem Statement	: print the only endpoitns of horizontal or vertivcal line segments
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Node
	{
		int x;
		int y;
		Node next;
		
		Node(int x, int y)
		{
		this.x = x;
		this.y = y;
		this.next = null;
		}
	}
class RemoveMidpointsofLineSegments
{
	Node head;
	
	public void push(int x,  int y)
		{
		Node node = new Node(x, y);
		node.next =  head;
		head =  node;
		
		}
	public void printPoints(Node node)
	{
		while(node != null)
			{
			
			System.out.print("( "+node.x+", "+node.y+" )");
			node =  node.next;
			}
	
	}	
	public void removeMidPoints(Node start)
	{
		if(start ==null ||  start.next == null || start.next.next==null)
			return;
			
		Node cur =  start;
		Node curNext =  cur.next;
		Node curNextNext =  curNext.next;
		//  check if x coordinates of cur and curNext same
		if(curNext.x ==cur.x)
		{
			while(curNext!=null &&curNextNext!=null &&  curNextNext.x==cur.x)
			{
				cur.next =  curNextNext;
				curNext =  curNextNext;
				curNextNext = curNextNext.next;
				
			}
			
			
		}else if (curNext.y ==cur.y)
		{
			while(curNext!=null &&curNextNext!=null &&curNextNext.y==cur.y)
			{
				cur.next =  curNextNext;
				curNext =  curNextNext;
				curNextNext =  curNextNext.next;
			}
			
			
		}else
		{
			System.out.println("invalid poitns");
			return;
			
		}
	
		removeMidPoints(cur.next);
	}
	public static void main(String args[])
	{
		RemoveMidpointsofLineSegments ls = new RemoveMidpointsofLineSegments();
		
		
	
		
		ls.push(40,5);
		ls.push(20,5);
		ls.push(7,5);
		
		ls.push(7,10);
		ls.push(5,10);
		ls.push(1,10);
		ls.push(0,10);
		ls.printPoints(ls.head);
		ls.removeMidPoints(ls.head);
		System.out.println();
		ls.printPoints(ls.head);
		
	}

}