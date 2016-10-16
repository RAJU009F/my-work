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
# Topic or Type 	: GFG/Hash
# Problem Statement	: Find the reduced form of the array
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class FindMissingElementsinRange
{
	
	public static void findMissingNumbers(int arr[], int low, int high)
	{
		
		HashSet<Integer> hs =  new HashSet<Integer>();
		
		
		
 		for(int i=0; i<arr.length; i++)
		{
				if(arr[i]>=low &&high>arr[i])
						hs.add(arr[i]);
			
		}
		
		
		for(int num = low; num<high; num++)
				if(!hs.contains(num))
					System.out.println(num);
		
		
		
	}
	
	public static void main(String args[])
	{
		
		int arr[] = {10, 12, 11, 15};
		findMissingNumbers(arr,  10, 15);
	}
	
	
	
}