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
# Problem Statement	: Egg Dropping puzzle
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class GFG {
    
    public static int noOfTrials(int N, int K)
        {
            
            int[][]  dp = new int[N+1][K+1];
            
            // for 1 floor and 0 floor the trials
            
            for(int i=0; i<=N; i++)
                {
                    dp[i][0] = 0;
                    dp[i][1] = 1;
                    
                }
    // for only 1 egg case
            for(int j=0;j<=K; j++)
                dp[1][j] = j;
                
                
            for(int i=2; i<=N; i++)
                for(int j=2; j<=K; j++)
                    {
                        dp[i][j] = Integer.MAX_VALUE;
                        for(int  x=1; x<=j; x++)
                            {
                                int res = Math.max(dp[i-1][x-1], dp[i][j-x])+1;
                                if(res<dp[i][j])
                                    dp[i][j] = res;
                                
                            }
                        
                    }
                
                
            return dp[N][K];
            
            
        }
    
	public static void main (String[] args) {
		
	    Scanner sc =  new Scanner (System.in);
	    
	    int T  = sc.nextInt();
	    
	    while(T-->0)
	        {
	            
	            int N =  sc.nextInt();
	            int K =  sc.nextInt();
	            
	            System.out.println(noOfTrials(N, K));
	            
	        }
	
		
	}
}