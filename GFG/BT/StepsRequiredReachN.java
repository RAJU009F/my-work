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
# Problem Statement	:  Steps required to reach n
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
				this.data = data;
				this.l = this.r = null;
			}
	
	}
	
class StepsRequiredReachN
		{
			public int toReachN(int N)
			{
				if(N==0)
				return 0;
				
				Queue<Integer> q =  new LinkedList<Integer>();
				q.add(0);
				int steps = 1;
				while(!q.isEmpty())
				{
					int n = q.size();
					while(n>0)
					{
						
						int i = q.peek();
						if(i==N)
							return steps;
						q.poll();
					
						q.add(i-steps);
						q.add(i+steps);
						
						n--;
					}
					steps +=1;
				}
					return -1;
			}	
			
		public static void main(String args[])
				{
					StepsRequiredReachN bt = new StepsRequiredReachN();
					
					System.out.println("To reach 10 steps required"+bt.toReachN(10));
					System.out.println("To reach 20 steps required" + bt.toReachN(20));
			
				
				}
		
		}
		