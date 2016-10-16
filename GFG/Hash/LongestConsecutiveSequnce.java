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
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Matrix
# Problem Statement	: submatrix sum querries
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class LongestConsecutiveSequence

{
		public static  int longestConsecutiveSequence(int arr[])
		{
			int max_len = Integer.MIN_VALUE;
			int last_seq =0 ;
			
			HashSet<Integer> hs  = new HashSet<Integer>();
			
			for(int i=0; i<arr.length; i++ )
					hs.add(arr[i]);
			
			for(int i=0; i<arr.length; i++)
			{
				if(hs.contains(arr[i]-1))
				{
					int j= arr[i];
					
					while(hs.contains(j))
							j++;
						
					
					max_len = max_len>(j-arr[i]+1)?max_len:	(j-arr[i]+1);
					last_seq = max_len>(j-arr[i]+1)?last_seq: j;
					
				}
				
			}
			
			for(int i=last_seq-max_len; i<=max_len; i++)
				System.out.println(" "+i);
			return max_len;
		}
	
	
	public static  void main(String args[])
	{
		
		int  arr[] ={1, 9, 3, 10, 4, 20, 2, 7,6,5};

		
		System.out.println(longestConsecutiveSequence(arr));
		
		
	}
}

