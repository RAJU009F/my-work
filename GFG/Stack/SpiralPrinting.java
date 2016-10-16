import java.io.*;
import java.lang.*;
import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
 // #include <stdlib.h>
 // #include <string.h>
 // #include<stdbool.h>
 // #include<limits.h>

// # // #include<iostream>
// # // #include<algorithm>
// # // #include<string>
// # // #include<vector>
// # // using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Stacks
# Problem Statement	: Spiral tree level order printing
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
*/

class BT 
{
	int data;
	BT l;
	BT r;
	
	BT(int data)
	{
		this.data = data;
		this.l = this.r = null;
		
	}
	
}



class SpiralPrinting
{
	static BT root;
	
	public void spiralprint(BT node)
	{
		
		if(node==null)
			return;
		
		Stack<BT> s1 = new Stack<BT>();
		Stack<BT> s2 = new Stack<BT>();
		s1.push(node);
		while(!s1.empty() || !s2.empty())
		{
			
			while(!s1.empty())
			{
				BT temp = s1.pop();
				System.out.print(temp.data);
				
				if(temp.r!=null)
					s2.push(temp.r);
				if(temp.l!=null)
					s2.push(temp.l);
				
			}
			
			System.out.println();
			while(!s2.empty())
			{
				BT temp = s2.pop();
				System.out.print(temp.data);
				
				if(temp.l!=null)
					s1.push(temp.l);
				if(temp.r!=null)
					s1.push(temp.r);
				
				
			}
			
			System.out.println();
			
		}
		
		
	}

	
	
	
	public static void main(String args[])
	{
		SpiralPrinting sp = new SpiralPrinting();
		sp.root = new BT(1);
		sp.root.l = new BT(2);
		sp.root.r = new BT(3);
		sp.root.l.l = new BT(4);
		sp.root.l.r = new BT(5);
		sp.root.r.l = new BT(6);
		sp.root.r.r = new BT(7);
		
		sp.spiralprint(root);
		
		
	}
	
	
}