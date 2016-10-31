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
# Problem Statement	:   construct the Ancestor matrix 
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
				this.data =  data;
				this.l = this.r = null;
			}
	
	}
	
class Util
	
class AncestorMatrixBT

		{
		
		Node root;
		public int countNodes(Node node)
		{
			if(node == null)
					return 0;
				
			return countNodes(node.l)+1+countNodes(node.r);	
			
			
		}
		
		public void printAncestorMatrixUtil( Node node,  int mat[][], int ans[], int index)
		{
			
			if(node == null)
				return;
			
			int data = node.data;
			
			for(int i =0; i<ans.length; i++)
					mat[ans[i]][data] = 1;
				
			ans[index] = data;
			
			printAncestorMatrixUtil(node.l, mat, ans, index+1);
			printAncestorMatrixUtil(node.r, mat, ans, index+1);
			index--;
			
			
		}
		
		public void printAncestorMatrix(Node node)
		{
			if(root==null)
				return;
			
			int n  = countNodes(node);
			
			int[][] mat = new int[n][n];
			
			int[]  ans  =  new int[n];
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					mat[i][j] = 0;
				
			printAncestorMatrixUtil(node, mat, ans, 0);
			
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					System.out.print(mat[i][j] + " ");
				}
				System.out.println();
			}
			
			
			
		}
		
		
		public static void main(String args[])	
		{
				AncestorMatrixBT bt  = new AncestorMatrixBT();
				
				bt. root  =  new Node(5);
				bt.root.l =  new Node(1);
				bt.root.l.l =  new Node(0);
				bt.root.l.r  =  new Node(4);
				bt.root.r = new Node(2);
				bt.root.r.l = new Node(5);
				
				bt.printAncestorMatrix(bt.root);
				
				
		}
		
		
		}
	
	
