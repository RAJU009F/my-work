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
# Problem Statement	: longest Polindrome
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class GFG {
    
    public static String longestPolin(String str)
        {
            
            char[]  arr = str.toCharArray();
            String polin = String.valueOf(arr[0]).toString();
            
            int max_start =0;
            int max_end = 0;
            int start = 0;
            int end = 0;
            int max_len = 1;
            for(int i=1; i<arr.length; i++)
                {
                    
                    // case-1 odd length polin
                    start = i-1;
                    end  = i+1;
                    
                    while(start>=0 && end<=arr.length-1&& arr[start]==arr[end])
                        {
                            start--;
                            end++;
                        }
                    if(end-1-start>max_len)
                        {
                            max_start = start+1;
                            max_end = end-1;
                            max_len = end-1-start;
                        }
                        
                   start = i-1;
                    end  = i;
                    
                    while(start>=0 && end<=arr.length-1&& arr[start]==arr[end])
                        {
                            start--;
                            end++;
                        }
                    if(end-1-start>max_len)
                        {
                            max_start = start+1;
                            max_end = end-1;
                         max_len = end-1-start;
                        } 
                    
                }
            
            if(max_len>1)
                {
                    
                    polin = "";
                    for(int i=max_start; i<=max_end; i++)
                        polin = polin+String.valueOf(arr[i]).toString();
                    
                }
            return polin;
            
        }
	public static void main (String[] args) {
	
	    Scanner sc =  new Scanner(System.in);
	    
	    int T =  sc.nextInt();
	    
	    while(T-->0)
	        {
	            String str =  sc.next();
	            
	            System.out.println(longestPolin(str));
	            
	            
	        }
	
	
	
	}
}