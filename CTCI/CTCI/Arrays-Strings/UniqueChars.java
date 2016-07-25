
import java.io.*;
import java.lang.*;
import java.util.*;

/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: Check String has unique chars
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class UniqueChars
{
	public static void heapiFy(char arr[], int i, int size)
	{
		int max = i;
		int l = 2*i+1;
		int r = 2*i+2;
		if(l<size && arr[max]<arr[l])
			max = l;
		if(r<size && arr[max]<arr[r])
			max = r;
		if( i !=max)
		{
			char c = arr[i];
			arr[i] = arr[max];
			arr[max] = c;
			heapiFy(arr, max, size);
			
		}
		
		
		
		
	}
	
	
	public static void sort(char arr[])
	{
		
		for(int i=arr.length/2-1; i>=0; i--)
				heapiFy(arr, i, arr.length);
			
		for(int i=arr.length-1; i>=0; i--)
		{
			char c = arr[i];
			arr[i] = arr[0];
			arr[0] = c;
			heapiFy(arr, 0, i);}
		
		
		
	}
	
	
	public static boolean isUnique(char str[])
	{
		sort(str);
		
		
		for(int i=0; i<str.length-1; i++)
				if(str[i] == str[i+1])
					return false;
		
		return true;
	}
	
	public static void main(String args[])
	{
		// String str = "MALAYALAM";
		String str = "ABCD";
		char[] arr = str.toCharArray();
		if(isUnique(arr))
				System.out.println("Unique");
		else
				System.out.println("Not Unique");
	
	
	}
	
	



}