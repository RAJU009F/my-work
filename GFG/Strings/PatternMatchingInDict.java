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
# Problem Statement	: print all the words in a dictionary which are matching with a given pattern string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class PatternMatchingInDict
{
	public static String encode(String pat, int n)
	{
		String res = "";
		int i=0;
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		char[] A =  pat.toCharStrings();
		for(char ch: A )
		{
			if(!(map.containsKey(ch)))
			{
				i++;
				map.put(ch, i);
			}
			
			res = res+String.valueOf(map.get(ch));
			
		}
		
		return res;
	}
	
	public static void printMatchedWords(Set<String> dict, String pattern)
	{
		int len = pattern.length();
		String hash = encode(pattern, len);
		
		for(String s: dict)
		{
			if(s.length()==len && hash.equals(encode(s, s.length())))
				System.out.println(s);
			
		}
		
		
		
	}
	public static void main(String args[])
	{
		HashSet<String> dict = new HashSet<String>();
			// dict.add("abc");
			// dict.add("abb");
			// dict.add("xyyy");
			// dict.add("xyz");
			dict.add("aab");
			
		String pattern = "xyy";
		printMatchedWords(dict, pattern);	
	}



}