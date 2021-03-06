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
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class ZigZag
{
	public static void zigZag(int arr[],  int n)
	{
		boolean f = true;
		for(int i=0; i<n-1 ;i++)
		{
			if(f)
			{
				if(arr[i]>arr[i+1])
				{
					arr[i] ^=arr[i+1];
					arr[i+1] ^=arr[i];
					arr[i] ^=arr[i+1];
				}
			}else
			{
				if(arr[i]<arr[i+1])
				{
					arr[i] ^=arr[i+1];
					arr[i+1] ^=arr[i];
					arr[i] ^=arr[i+1];
					
				}
			}
			
			f =!f;
			
		}
		
	}
	
	public static void main(String args[])
	{
		
		int arr[] = {4, 3, 7, 8, 6, 2, 1};
		zigZag(arr, arr.length);
		
		for(int i=0; i<arr.length; i++)
			System.out.println(arr[i]);
	}
	
	
}