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
# Problem Statement	:  # of distinct elements in  window k
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class SubArrayWith0Sum
{
 public static  void main(String args[])
 {
	 int arr[] = {};
	 
	 
 }
	
	
	
}


class DistinctElementsinKWindow
{
	public static  void distinctElementsK(int arr[], int k)
	{
		int dist_count = 0;
		int n  = arr.length;
		
		HashMap<Integer, Integer> hm =  new HashMap<Integer, Integer>();
		
		
		for(int i=0; i<k; i++)
		{
			
			if(hm.get(arr[i])==null)
			{
				hm.put(arr[i], 1);
				dist_count++;
				
			}else
			{
				hm.put(arr[i], hm.get(arr[i])+1);
				
			}
			
		}
		
		//  print the first distin elemnts from first k window 
		
		System.out.println(dist_count);
		
		for(int i=k; i<n; i++)
		{
			
			// remove the start element 
			if(hm.get(arr[i-k])==1)
			{
				hm.remove(arr[i-k]);
					dist_count--;
			}else
			{
				hm.put(arr[i-k], hm.get(arr[i-k])-1);
				
			}
			
			// add the new elemnt
			
			if( hm.get(arr[i]) == null )

			{
				
				dist_count++;
				hm.put(arr[i], 1);
				
				
			}else
			{
				hm.put(arr[i], hm.get(arr[i])+1);
				
			}
			
			System.out.println(dist_count);
			
		}
		
		
		
	}
	

	public static void main(String args[])
	{
		
		int arr[] = {1, 2, 1, 3, 4, 2, 3};
		
		distinctElementsK(arr, 4);
	
	}


}
