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
// #include<map>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: Product Pair 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class ProductPair
{
	public static void producPair(int arr[],  int n, int x) 
	{
		HashSet<Integer> set =  new HashSet<Integer>();
		
		for(int i=0; i<n; i++)
		{
			if(arr[i] == 0 && x==0)
			{
				System.out.println("x = "+x);
			return;
			}
			if(x%arr[i]==0)
			{if(set.contains(arr[i]))
				System.out.println(arr[i]+" * "+x/arr[i]+" = "+x);
			else
				set.add(x/arr[i]);
			}
			
			
		}
		
		
		
	}
	
	public static void main(String args[])
	{
		int arr[] = {-10, 20, 9, 40};
		
		int x= 800;
		producPair(arr, arr.length, x);
		
	}
	
	
}