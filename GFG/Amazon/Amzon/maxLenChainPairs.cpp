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
# Topic or Type 	: GFG/Graphs
# Problem Statement	: Topological Sort
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/



struct val
{
	int first;
	int second;
};

void swap(struct  val &a, struct val &b)
    {
        struct val t = b;
        b = a;
        a =t;
        
    }

void heapiFy(struct val p[],  int i,  int size )
    {
        int max =  i;
        int l =  2*i+1;
        int r  =  2*i+2;
        
        if(l<size && p[max].second<p[l].second)
            max =  l;
        if(r<size && p[max].second<p[r].second)
            max = r;
        if(max !=i)
            {
                swap(p[max], p[i]);
                heapiFy(p, max, size);
            }
    }
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    
    for(int i=n/2-1; i>=0; i--)
        {
            heapiFy(p, i, n);
            
        }
    
    for(int i=n-1; i>=0; i--)
        {
            swap(p[i], p[0]);
            heapiFy(p, 0, i );
            
        }
        
    int maxlen = 0;
    struct val a =  p[0];
    for(int i=1; i<n; i++)
        {
            if(a.second < p[i].first )
            {    
                maxlen++;
                
                a = p[i];
            }
            
        }
    cout<< maxlen;
    return maxlen;
}

struct val newNode(int a, int b)
{
	struct val  node =  new struct val;
	node.first = a;
	node.second = b;
	
}

int main()
{
	
	struct val p[5];
	p[0] = newNode(5, 24);
	p[1] = newNode(39, 60);
	p[2] = newNode(15, 28);
	p[3] = newNode(27, 40);
	p[4] = newNode(50, 90);
	
	
}