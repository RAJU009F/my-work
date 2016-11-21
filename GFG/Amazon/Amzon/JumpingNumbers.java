// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: calcullate the water among buildings
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class GFG {
    
    public static void BFS(int n, int N)
        {
            
            Queue<Integer> q =  new LinkedList<Integer>();
            
            q.add(n);
            
            while(!q.isEmpty())
                {
                    n =  q.peek();
                    q.poll();
                    if(n<=N)
                    {
                    System.out.print(n+" ");
                    
                    int last_d = n%10;
                    if(last_d == 0)
                        q.add(n*10+1);
                    else if(last_d==9)
                        q.add(n*10+last_d-1);
                    else
                        {
                            
                            q.add(n*10+last_d+1);
                            q.add(n*10+last_d-1);
                        }
                    
                    }
                    
                }
            
            q.clear();
        }
    
    public static void printJumpingNum(int N)
        {
            
            System.out.print(0+" ");
        
        for(int i=1; i<=9; i++)
            {
                BFS(i, N);
                
                
                
            }
            
            
            
        }
    
	public static void main (String[] args) {
		
		Scanner sc =  new Scanner(System.in);
		
		
		int T =  sc.nextInt();
		
		while(T-->0)
		    {
		        
		        int N=  sc.nextInt();
		        
		        printJumpingNum(N);
		        
		        System.out.println();
		        
		    }
		
		
		
	}
}