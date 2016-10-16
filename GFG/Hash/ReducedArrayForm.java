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

class ReducedArrayForm
{
	public static  void printArray(int arr[])
	{
		
		for(int i=0; i<arr.length; i++)
			System.out.println(arr[i]);
		
	}
	
	public static  void reducedArrayForm(int arr[])
	{
		
		int n =  arr.length;
		int[]  temp =  new int[n];
		
		// move the elements into temp 
		// push all the elements in to hashmap
		HashMap<Integer, Integer>  hm = new HashMap<Integer, Integer>();
		for(int i=0; i<arr.length; i++)
		{temp [i] = arr[i];
			hm.put(arr[i], i);
		}
		
		
	
		// sort the elements in temp;
		
		Arrays.sort(temp);
		
		int value = 0;
		// travers the elements in temp and use hashmap and 
		for(int i=0; i<n; i++)
		{
			int index =  hm.get(temp[i]);
			arr[index]  = value++;
			
		}
		
		
		
		
		
	}
	
	
	
	public static void main(String args[])
	{
		int  arr[] = {5, 10, 40, 30, 20};
		
		System.out.println("Before Reduce ");
		printArray(arr);
		reducedArrayForm(arr);
		System.out.println("After Reduce");
		printArray(arr);
		
		
	}



}

