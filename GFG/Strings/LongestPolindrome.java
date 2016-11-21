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

class LongestPolindrome
{
	public static void longestPloindrome(String str)
	{
		int start;
		int end;
		int len = str.length();
		int maxlen = 0;
		int s=0,e=0;
		for(int i=1; i<len; i++)
		{
			start = i-1;
			end = i;
			
			while(start>=0 &&end<len && str.charAt(start)==str.charAt(end))
			{
				if(end-start+1>maxlen)
				{
					maxlen = end-start+1;
					s= start;
					e = end;
				}
				start--;
				end++;
			}
			
			start = i-1;
			end = i+1;
				
			
			while(start>=0 &&end<len && str.charAt(start)==str.charAt(end))
			{
				if(end-start+1>maxlen)
				{
					maxlen = end-start+1;
					s= start;
					e = end;
				}
				start--;
				end++;
			}
			
		}
		
		System.out.println("maxlen : "+maxlen);
		System.out.println("Pol String is : "+str.substring(s, e+1));
		
	}
	
	public static void main(String args[])
	{
		String str  = "malayalammonomor";
		longestPloindrome(str);
	}
	
	
}