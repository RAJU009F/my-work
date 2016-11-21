import java.lang.*;
import java.util.*;
import java.io.*;

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
// #include<queue>
// using namespace std;

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


class ThreeIncreaseSequence
	{
		public  void subSequence(int arr[])
		{
			int N  =  arr.length;
			int[] small =  new int[N];
			
			small[0] = -1;
			int min = 0;
			for(int i=1; i<N; i++)
			{
				if(arr[i]>=arr[min])
				{
					small[i] =  min;
					
				}else
				{
					min = i;
					small[i] = -1;					
				}
			}
			
			int[] greater = new int[N];
			
			greater[0] =  -1;
			int max = N-1;
			
			for(int i=N-2; i>=0; i--)
			{
				if(arr[i]<=arr[max])
					greater[i] = max;
				else
				{
					greater[i] = -1;
					max  = i;
					
				}
			}
			
		for(int i=0; i<N; i++)
		{
			if( small[i]!=-1 &&greater[i]!=-1)
			{
			System.out.println(arr[small[i]]+" "+arr[i]+" "+arr[greater[i]]);
				return;
			}
			
			
			
		}
			
			System.out.println(" triplet not found ");
		}
		
		public static void main(String args[])
		{
			
			ThreeIncreaseSequence t =  new ThreeIncreaseSequence();
			int arr[]  = {12, 11, 10, 5, 6, 2, 30};
			t.subSequence(arr);
		}
	
	}