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
# Problem Statement	: 1: longest width  i.e max nodes in a level  
					  2: root to leaf paths
					  3: ROOT TO LEAF PATH WITH GIVEN SUM EXISTS
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
			this.data =data;
			this.l = null;
			this.r = null;
		}
	}
	
class LongestWidth
{
	Node root;
	
	public int maxWidth(Node node)
	{
		if(node == null)
				return 0;
		Queue<Node> q =  new LinkedList<Node>();

		q.add(node);
		q.add(null);
		int max = 1;
		int count = 0;
		while(q.isEmpty() == false)
		{
			
			 node = q.peek();
			q.poll();
			if(node == null)
			{
				
				if(count > max)
				{
					max  = count;
					
				}
				if(q.isEmpty() == false)
					{
					count  = 0;
					q.add(null);
				
					}else
						break;
				
			}else
			{
			count = count +1;
			if(node.l != null)
			{
				q.add(node.l);
				
			}
			if(node.r != null)
				q.add(node.r);
			}
			
			
		}
		
			return max;
		
	}
	
	public int height(Node root)
	{
		if(root == null)
			return 0;
		
		int lh  =  height(root.l);
		int rh  = height(root.r);
		
		return (lh>rh?lh:rh)+1;
		
	}
	
	public void printPaths(int arr[], int n)
	{
		
		for(int i=0; i<n; i++)
			System.out.print(arr[i]+" ");
		System.out.println();
		
		
	}
	public  void rootToLeafPathsUtil(Node root,  int arr[], int index)
	{
		if(root == null)
			return;
		arr[index] = root.data;
		
		index++;
		
		if(root.l == null && root.r == null)
		{
			printPaths(arr, index);
			return;
			
		}
		
				rootToLeafPathsUtil(root.l, arr, index);
				rootToLeafPathsUtil(root.r, arr, index);	
	}
	
	public boolean isSumExists(Node root,  int path[], int index, int sum)
	{
		if(root !=null)
		{
			//System.out.println(index);
			path[index] = root.data;
			int temp = 0;
			
			for(int i=0; i<index; i++)
			{
				temp +=path[i];
				if(sum==temp)
					return true;
				
			}
			return isSumExists(root,  path,  index+1,  sum)|| isSumExists(root, path,  index+1,  sum);
		}
		
		return false;
		
	}
	public void rootToLeafPaths(Node root)
	{
		if(root == null)
			return ;
		int h =  height(root);
		int[] path =  new int[h+1];
		System.out.println(isSumExists(root, path, 0, 23));
		
		// int[] arr =  new int[h];
		
		// rootToLeafPathsUtil(root, arr, 0);
		
	}
	public static void main(String args[])
	{
		LongestWidth bt =  new LongestWidth();
		bt.root =  new Node(1);
		bt.root.l = new Node(2);
		bt.root.r = new Node(3);
		bt.root.l.l =  new Node(4);
		bt.root.l.r =  new Node(5);
		
		bt.root.r.r = new Node(8);
		bt.root.r.r.l =  new Node(6);
		bt.root.r.r.r =  new Node(7);
		
		System.out.println(bt.maxWidth(bt.root));
		
		
		bt.rootToLeafPaths(bt.root);
		
		
		
	}


}	