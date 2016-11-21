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
    
    public static void  printMatchUtil(char arr[], int N)
    {
        
        for(int i=0; i<N; i++)
            System.out.print(arr[i]+" ");
        
         System.out.println();
        
    }
    
    public static int partition(char arr[],  int left, int right, char pivot)
        {
            int i = left;
            
            for(int j=left; j<right; j++)
                {
                    if(arr[j]<pivot)
                        {
                            char t  = arr[j];
                            arr[j] = arr[i];
                            arr[i] = t;
                                 i++;   
                        }else if(arr[j]==pivot)
                            {
                                char t  = arr[j];
                            arr[j] = arr[right];
                            arr[right] = t;
                                 j--; 
                                
                                
                            }
                    
                }
                
            char t  = arr[i];
                arr[i] = arr[right];
                arr[right] = t;
     
        return i;
            
            
        }
    public static void quicksort(char nuts[],  char  bolts[],  int left, int right)
        {
            
            if(left<right)
                {
                    int pivot  = partition(nuts, left, right, bolts[right]);
                    
                    partition(bolts, left, right, nuts[pivot]);
                    
                    quicksort(nuts, bolts, left, pivot-1);
                    quicksort(nuts, bolts,  pivot+1, right);
                    
                }
            
            
            
        }
    
    public static void  printMatch(char nuts[],  char bolts[],  int N)
        {
            
            quicksort(nuts, bolts, 0, N-1);
            
            printMatchUtil(nuts, N);
            printMatchUtil(bolts, N);
            
        }
    
	public static void main (String[] args) {
		
		Scanner sc =  new Scanner(System.in);
		
		int T  =  sc.nextInt();
		
		while(T-->0)
		    {
		        
		        int N = sc.nextInt();
		        char[]  bolts =  new char[N];
		        char[]  nuts = new char[N];
		        
		        for(int i=0; i<N; i++)
		            bolts[i] =  sc.next().toCharArray()[0];
		            
		         for(int i=0; i<N; i++)
		            nuts[i] =  sc.next().toCharArray()[0];
		        
		        printMatch(nuts, bolts, N);
		        
		    }
		
		
		
	}
}