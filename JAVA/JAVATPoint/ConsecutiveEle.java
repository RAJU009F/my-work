import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: ConsecutiveEle.java
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class ConsecutiveEle
{

boolean consecutive(int arr[], int n)
{
	int max=arr[0];
	int min=arr[0];
	for(int i=0; i<n; i++)
	{
		if(arr[i]>max)
			max = arr[i];
		if(arr[i]<min)
			min = arr[i];
	}	
	sum =  n*(n+1)/2;
	if(max-min+1==n)
	{
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			sum -=(arr[i]-min-1);
			
		}
		
	if(sum==0)
			return true;
	else	
			return false;
	}
	}
	
	
	
}

public static void main(String args[])
{
	int arr[] = {};
	
	if(consecutive(arr[], n))
		System.out.println("Consecutive");
	else
		System.out.println("Not Consecutive");
}

}