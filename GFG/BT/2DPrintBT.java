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
# Problem Statement	:  2D print of BT
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
	
	Node( int data)
		{
			this.data = data;
			this.l = this.r = null;
		
		}
	

}

class BT2DPrint
	{
	
		Node root;
		
		public  void Inorder2D(Node node, int space)
			{
				if(node == null)
					return;
				space +=5;
				Inorder2D(node.l, space);
					System.out.println();
					for(int i=0; i<space; i++)
						System.out.print(" ");
					System.out.println(node.data);
				Inorder2D(node.r, space);		
			}
			
		public  void PreOrder2D(Node node, int space)
			{
				if(node == null)
					return;
				space +=5;
				System.out.println();
					for(int i=0; i<space; i++)
						System.out.print(" ");
					System.out.println(node.data);
				
				PreOrder2D(node.l, space);
					
				PreOrder2D(node.r, space);		
			}	
		
		public void PostOrder2D(Node node, int space)
			{
				if(node == null)
					return;
				space +=5;
				
					
				
				PostOrder2D(node.l, space);
					
				PostOrder2D(node.r, space);
				System.out.println();
				for(int i=0; i<space; i++)
						System.out.print(" ");
					System.out.println(node.data);
			
			}
		
		public static void main(String args[])
			{
			
				BT2DPrint bt =  new BT2DPrint();
				
				bt.root =  new Node(1);
				bt.root.l =  new Node(2);
				bt.root.r =  new Node(3);
				bt.root.l.l =  new Node(4);
				bt.root.l.r =  new Node(5);
				bt.root.r.l = new Node(6);
				bt.root.r.r = new Node(7);
				
				//System.out.println(node.data+" ");
				int space =10;
				System.out.println("Inorder print");
				bt.Inorder2D(	bt.root, space);
					System.out.println("Preorder print");
				bt.PreOrder2D(	bt.root, space);
					System.out.println("Postorder print");
				bt.PostOrder2D(	bt.root, space);
			
			}
	
	
	}
