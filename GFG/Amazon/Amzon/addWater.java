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
    public static int addWater(int arr[],  int N)
        {
            int water = 0;
            
            int[]  left =  new int[N];
            int[]  right  =  new int[N];
            
            left[0] = arr[0];
            
            for(int i=1; i<N; i++)
                left[i] =  Math.max(arr[i], left[i-1]);
            right[N-1] =  arr[N-1];
            
            for(int i=N-2; i>=0; i--)
                right[i] =  Math.max(arr[i], right[i+1]);
            
            for(int i=0; i<N; i++)
                water  += Math.min(left[i], right[i])-arr[i];


            return water;            
            
        }
    
    
    
	public static void main (String[] args) {
	
	    Scanner sc =  new Scanner(System.in);
	    
	    int T =  sc.nextInt();
	    
	    while(T-->0)
	        {
	            
	            int N =  sc.nextInt();
	            int[]  arr  =  new int[N];
	            
	            for(int i=0; i<N; i++)
	                arr[i] = sc.nextInt();
	                
	           System.out.println(addWater(arr, N));     
	            
	        }
	
	
	}
}