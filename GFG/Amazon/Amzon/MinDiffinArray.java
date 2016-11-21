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
# Problem Statement	: min diff in array
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
class MinDiffinArray {
	public static void main (String[] args) {
	
	    Scanner sc =  new Scanner(System.in);
	    int T = sc.nextInt();
	    
	    while(T-->0)
	    {
	        
	        int N = sc.nextInt();
	        int[] arr =  new int[N];
	        int[] count = new int[100001];
	        int diff = -1;
	        for(int i=0; i<N; i++)
	            {
	                arr[i] =  sc.nextInt();
	                count[arr[i]]++;
	                
	            }
	       int pos = 0 ;
	       for(int i=0; i<100001;i++)    
	            {
	                if(count[i]==1)
	                    arr[pos++] = i;
	               else if (count[i] > 1)
	                {
	                    diff = 0;
	                    break;
	                }
	                
	            }
	        
	        if(diff!=0)
	            {
	                diff = Integer.MAX_VALUE;
	                for(int i=0; i<N-1; i++)
	                    {
	                        if(arr[i+1]-arr[i]<diff)
	                            diff = arr[i+1]-arr[i];
	                        
	                    }
	                
	            }
	            System.out.println(diff);
	        
	        
	    }
	}
}