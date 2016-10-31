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
# Problem Statement	:  Noof cycles required to rotten the ornages
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/

class Point 
	{
	
		int x;
		int y;
		
		Point(int x, int y)
			{
				this.x  = x;
				this.y = y;
			}
	
	}
class RottenOranges
		{
		
			public boolean isValid(int x, int y,  int m,  int n)
			{
				
				return x>=0 && x<m && y>=0&&y<n;
				
				
			}
			
			public boolean isAllRotten(int arr[][])
			{
				
				for(int i=0; i<arr.length; i++)
				{
					for(int j=0; j<arr[0].length; j++)
					{
						if(arr[i][j]==1)
								return false;
					}
					
				}
			
				
				return true;
			}
			public int noofCycles(int arr[][])
				{
				
					int R[] = {-1,0,0,1};
					int C[] = {0,-1,1,0};
				
					int m  =  arr.length;
					int n =  arr[0].length;
					System.out.println(m+" "+n);
					Queue<Point> q=  new LinkedList<Point>();
					
					// 
					for(int i=0; i<m; i++)
					{
						for(int j=0; j<n; j++)
						{
							if(arr[i][j] == 2)
							{
								Point p = new Point(i, j);
								q.add(p);
							}
							
					}}
					int cycles  = 0;
					boolean flag = false;
					while(!q.isEmpty())
					{
						int size  =  q.size();
						// cycles++;
						while(size>0)
						{
							Point t =  q.peek();
							q.poll();
							
							for(int i=0; i<4; i++)
							{	
								int x  =  t.x + R[i];
								int y  =  t.y + C[i];
								if(isValid(x,y,m,n)&&arr[x][y]==1)
								{
									Point np  =  new Point(x, y);
									q.add(np);	
									System.out.println("reeeee");	
									arr[x][y] = 2;
									flag = true;
								
								}
								
							}
							//System.out.println(t.x+" "+t.y);
							
							size--;
						}
						
						if(flag)
						{	flag =false;
							cycles++;
					}
						
						
						
					}
				
				return !isAllRotten(arr)?-1:cycles;
				
				
				}
			
			
			public static void main(String args[])
			{
				RottenOranges o  =  new RottenOranges();
			
				int arr[][] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};

				
				System.out.println(o.noofCycles(arr));
			}
		
		}
	
	