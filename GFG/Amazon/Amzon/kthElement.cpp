// import java.lang.*;
// import java.util.*;
// import java.io.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: 
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/


struct hNode
    {
        int d;
        int i;
        int j;
        
    };
    
void heapify(struct hNode h[], int i, int size)
    {
        int min = i;
        int l  =  2*i+1;
        int r =  2*i+2;
        
        if(l<size && h[l].d<h[min].d)
            min = l;
        if(r<size && h[r].d < h[min].d)
            min = r;
        if(min!=i)    
        {
            struct hNode t = h[min];
            h[min] = h[i];
            h[i] = t;
            heapify(h, min , size);
            
        }
        
    }

int kthSmallest(int mat[4][4], int n, int k)
{
  
 struct hNode h[k];
	int kthE=	-1;
    // Method-1 : Use Heap
        for(int i=0; i<n;i++)
            {
            
                h[i].d =  mat[i/n][i%n];
                h[i].i = i/n;
                h[i].j = i%n;
            } 
  
        for(int i=k/2-1; i>=0; i--)
                heapify(h, i, k);
        for(int i=0; i<k; i++)
            {
                
                struct hNode e = h[0];
                kthE = e.d;
                h[0].d = mat[(e.i+1)][e.j];
                h[0].i = e.i+1;
                h[0].j = e.j;
                heapify(h, 0, k);
            }
		return kthE;	
}

int main()
{
	int mat[][4] = {{16 ,28, 60, 64},{ 22, 41, 63, 91} ,{27, 50, 87, 93}, {36, 78, 87, 94} };
	cout<<kthSmallest(mat, 4, 3);
	
}