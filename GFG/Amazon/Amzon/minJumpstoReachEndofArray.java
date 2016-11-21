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
# Problem Statement	: minimum number of jumps required to reach end of the array
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
class GFG {
    
    public static int minJumps(int arr[], int N)
        {
            int[]  jumps =  new int[N];
            int[]  result = new int[N];
            
            if(arr[0]==0)
                return -1;
            for(int i=0; i<N; i++)
                {
                    result[i] = Integer.MAX_VALUE;
                    jumps[i] = -1;
                }
            result[0] = 0;
            jumps[0] = 0;
            for(int i=1; i<N; i++)
                {
                    for(int j=0; j<i; j++)
                        {
                            if(i<=j+arr[j])
                                {
                                    if(result[i]>result[j]+1)
                                            {    result[i] =  result[j]+1;
                                                jumps[i] = j;
                                            }                                               
                                }
                            
                        }
                    
                    
                    
                }
              
            if(result[N-1]== Integer.MAX_VALUE)    
            return -1;
        
        return    result[N-1];
                
            
            
        }
    
	public static void main (String[] args) {
		
		Scanner sc =  new Scanner(System.in);
        
        int T =  sc.nextInt();
        
        while(T-->0)
            {
                int N =  sc.nextInt();
                
                int[]  arr =  new int[N];
                for(int i=0; i<N; i++)
                    {
                        arr[i] =  sc.nextInt();
                    }
                System.out.println(minJumps(arr, N));
                
            }
		
	}
}