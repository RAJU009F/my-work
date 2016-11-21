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
# Problem Statement	: two strings are mappings or not 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class areIsomorphic
{	
	public static int  hashcode(String str)
	{
		int len =  str.length();
		HashMap<Character, Integer> map =  new HashMap<Character, Integer>();
		int j=0;
		int hash = 0;
		for(int i =0; i<len; i++)
		{
			if(!map.containsKey(str.charAt(i)))
			{	j++;
				map.put(str.charAt(i), j );
			}
			
			hash = hash*10+j;
			
		}
		
		return hash;
	}
	
	public static boolean areMaps(String str1, String str2)
	{
		
		return (str1.length() == str2.length() && hashcode(str1) == hashcode(str2));
		
		
		
	}
	
	
	public static void main(String ars[])
	{
		if (areMaps("aab", "xxy"))
			System.out.println("Mappaings");
		else
			System.out.println("Not mapped ");
		if (areMaps("aab", "xyy"))
			System.out.println("Mappaings");
		else
			System.out.println("Not mapped ");
		
	}
	
	
}
// bool hashcode(char *str1, char *str2)
// {
	
	// int m = strlen(str1);
	// int n = strlen(str2);
	
	
	
// }

// bool areIsomorphic(char *str1, char *str2)
// {
	// if(strlen(str1)!=strlen(str2))
		// return false;
	// return hashcode(str1) == hashcode(str2);

// }

// int main()
// {
	// bool res = areIsomorphic("", "");
	// printf("%s", res?"Isomorphic":"Not Isomorphic");
	// return 0;

// }