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
# Problem Statement	:  Find the hight of special BT;
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
	
class HeightofLeevesConnectedBT
{
	Node root;
	
	public int height(Node node)
	{
		if(node==null)
			return 0;
		if(node.l.r == node && node.r.l ==node)
			return 0;
		
		int l =  height(node.l);
		int r  =  height(node.r);

			return (l>r?l:r)+1;
		
	}
	public static void main(String args[])
		{
			
		HeightofLeevesConnectedBT bt =  new HeightofLeevesConnectedBT();
		bt.root =  new Node(1);
		bt.root.l = new Node(2);
		bt.root.r = new Node(3);
		bt.root.l.l  =  new Node(4);
		bt.root.l.r  =  new Node(5);
		bt.root.r.l = new Node(6);
		bt.root.r.r = new Node(7);
		
		bt.root.l.l.l= bt.root.r.r;
		bt.root.r.r.r = bt.root.l.l;
		bt.root.l.l.r = bt.root.l.r;
		bt.root.l.r.l = bt.root.l.l;
		bt.root.l.l.r = bt.root.r.l;
		bt.root.r.l.l = bt.root.l.l;
		bt.root.r.l.r = bt.root.r.r;
		bt.root.r.r.l = bt.root.r.l;
		bt.height(bt.root);
		
		System.out.println("Height of special BT"+bt.height(bt.root));
		
		}


}	