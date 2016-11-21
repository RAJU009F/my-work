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
# Problem Statement	: find all the numbers with n digits forms the sum X
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class GFG {
    
    public static int rec(int N, int Sum)
        {
            if(N==0)
                return Sum==0?1:0;
            int r =0;    
            for(int i=0; i<=9; i++)
                 if(Sum-i>=0)
                     r += rec(N-1, Sum-i);
            
            return r;
        }
    
    public static int printdigitsSum(int N, int Sum)
        {
            
            int ans =0;
            
            for(int i=1; i<=9; i++)
                if(Sum-i>=0)
                    ans += rec(N-1, Sum-i);
            
            
            return ans;    
            
            
            
        }
    
	public static void main (String[] args) {
		
		Scanner sc  = new Scanner(System.in);
		
		int T =  sc.nextInt();
		
		while(T-->0)
		    {
		        int N =  sc.nextInt();
		        int sum = sc.nextInt();
		        
		        System.out.println(printdigitsSum(N, sum));
		        
		        
		    }
		
		
	}
}