import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: SOrting/Searching-Java 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class SortSearching{

public static void printArray(int arr[])
{
	
	for(int i=0; i<arr.length; i++)
		System.out.print(arr[i]+" ");
	
	
}


public static void mergeSortedArrays(int a[], int m,  int b[], int n)
{
	int i = m-1;
	int j = n-1;
	int k = m+n-1;
	
	while(i>=0&&j>=0)
	{
		if(a[i]>b[j])
		{b[k] = a[i];
			i--;}
		else
		{
			b[k] = b[j];
			j--;
		}
		k--;
		
	}
	
	if(i>=0)
		b[k--] = a[i--];
	if(j>=0)
		b[k--] = b[j--];
	
	
	
}

public static void main(String args[])
	{
	
	int[] a = {1,6,8,9,11};
	int [] b  =  new int[10];
	
	for(int i=0; i<5; i++)
		b[i] = i+i*3;
	
	printArray(a);
	System.out.println();
	printArray(b);
	System.out.println();
	mergeSortedArrays(a,5, b,5);
	System.out.println();
	printArray(b);
	
	

	}

}