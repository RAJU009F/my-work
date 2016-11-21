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
# Problem Statement	: count all possible 2 group and 3 group sum elements 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Multiple3groups {
    
    public static int countGroups(int count[])
        {
            int res  = 0;
            
        
            // group of 2,   and  case  any of 2 zero rem c(n, 2);
            res  += count[0]*(count[0]-1) /2;
            
            // group of 2 and case 1 is from zero rem and 1 is from 2 rem
            
            res += count[1]*(count[2]);
            
            // group 3: case any 3 from 0 remider c(n, 3);
            
            
            res += count[0]*(count[0]-1)*(count[0]-2) /6; 
            
            // group 3: case any 3 from 1 remider c(n, 3);
             res += count[1]*(count[1]-1)*(count[1]-2) /6; 
             
             //  group 3:  case any 3 from 2 reminder c(n, 3);
             
             res += count[2]*(count[2]-1)*(count[2]-2) /6; 
             
             // group 3:  1 from each rem
             
             res += count[0]*count[1]*count[2];
             
             
        //    System.out.println(re);
          return res;  
        }
	public static void main (String[] args) {
		
		
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		while (T-->0)
		    {
		        int N = sc.nextInt();
		        int[]  arr =  new int[N];
		        int[]  count = new int[3];
		        for(int i =0; i<N; i++)
		            {
		                arr[i] = sc.nextInt();
		                count[arr[i]%3]++;
		            }
		       System.out.println(countGroups(count ));
		        
		        
		        
		    }
		
		
		
	}
}