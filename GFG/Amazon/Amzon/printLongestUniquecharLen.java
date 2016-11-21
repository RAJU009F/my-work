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
# Problem Statement	: Nuts and Bolts
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class GFG {
    
    public static void printLongestUniquecharLen(char s[])
        {
            
            HashMap<Character, Integer> hm =  new HashMap<Character, Integer>();
            int cur_len = 0;
            int max_len = 0;
            Integer prev_index;
            for(int i=0; i<s.length; i++)
                {
                    
                   prev_index = hm.get(s[i]);
                    
                    if(prev_index==null || i-cur_len> prev_index)
                            cur_len++;
                    else
                        {
                            if(max_len<cur_len)
                                max_len = cur_len;
                            cur_len = i-prev_index;    
                        }
                        
                       
                    hm.put(s[i], i);
                    
                }
             if(max_len<cur_len)
                     max_len = cur_len;
                    
            System.out.println(max_len);
        }
    
	public static void main (String[] args) {
	    
	    Scanner sc =  new Scanner(System.in);
	    
	    int  T = sc.nextInt();
	    
	    while(T-->0)
	        {
	            String str  =  sc.next();
	            
	            char s[] =  str.toCharArray();
	            
	            printLongestUniquecharLen(s);
	            
	            
	        }
	    
	
	
	}
}