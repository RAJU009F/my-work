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
# Problem Statement	: max repeat number
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class GFG {
    
    public static int maxSumIncrSubSeq(int arr[] , int N)
        {
            
            int[] MIS= new int[N];
            
            for(int i=0; i<N; i++)
                MIS[i] = arr[i];
                
            for(int i=1; i<N; i++ )
                for(int j=0; j<i; j++)
                    {
                        if(arr[i]>arr[j] && MIS[i]<MIS[j]+arr[i])
                            MIS[i] = MIS[j] + arr[i];
                        
                        
                    }
            
            int max= MIS[0];
            
            for(int  i=1; i<N; i++) 
                {
                    if(max<MIS[i])
                        max = MIS[i];
                    
                }
            return max;
        }
    
	public static void main (String[] args) {
		
		Scanner sc =  new Scanner(System.in);
		
		int T =  sc.nextInt();
		
		while(T-->0)
		    {
		        
		        int N =  sc.nextInt();
		        
		        int[]  arr = new int[N];
		        for(int i=0; i<N; i++)
		            arr[i] =  sc.nextInt();
            System.out.println(maxSumIncrSubSeq(arr, N));		            
		    }
		
		
		
	}
}