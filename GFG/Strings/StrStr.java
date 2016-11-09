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
# Topic or Type 	: GFG/Strings
# Problem Statement	: Longest Ploindrome substring
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class StrStr
{
	public static void preProcess(String x, int n,  int LP[])
	{
		
		int i=1;
		LP[0] = 0;
		int len =0;
		while(i<n)
		{
			if(x.charAt(i)==x.charAt(len))
			{
				len++;
				LP[i] = len;
				i++;
			}else if(len>0)
				len = LP[len-1];
			else
			{
				LP[i]=0;
				i++;
			}
				
			
			
		}
		
		
	}
	
	public static int strstr(String s, String x)
	{
		
		int m =  s.length();
		int n =  x. length();
		int[] LP = new int[n];
		preProcess(x, n, LP);
		int i=0;
		int j=0;
		while(i<m)
		{
			if(s.charAt(i)==x.charAt(j))
			{
				if(j==n-1)
				{	System.out.println(i+" "+j);
					return i-j;}
				else
				{
					i++;
					j++;
				}
			}else if(j>0)
				j = LP[j-1];
			else
			{i++;
				j=0;
			}
			
			
			
		}
		
		return -1;
	}
	
	public static void main(String args[])
	{
		String  s = "GeeksForGeeks";
		String x = "For";
		// String  s = "ABCDAABCD";
		// String x = "AABC";
		System.out.println(strstr(s, x));
	}
}