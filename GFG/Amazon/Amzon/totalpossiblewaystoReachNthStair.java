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
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: total possible ways to reach Nth stair case
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class GFG {
    
    public static long  printSum(int N)
        {
            if(N<=2)
                return N;
         long a  = 1;
           long  b  = 2;
       long c = 2;
            for(int i=3; i<=N; i++)
                {
                    c  = (a+b)%(1000000007);
                    a = b;
                    b = c;
                    
                }
    
                        
            return c;
            
        }
        
        
	public static void main (String[] args) {
		
		Scanner sc =  new Scanner(System.in);
		
		int T  =  sc.nextInt();
		while(T-->0)
		    {
		        int N =  sc.nextInt();
		        
		        System.out.println(printSum(N));
		        
		        
		        
		        
		    }
		
		
		
	}
}