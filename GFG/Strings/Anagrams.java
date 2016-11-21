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
# Problem Statement	: print all the anagram strings together
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class Word
{
	int index;
	String string;
	
}

 class Anagrams{
	
	

	void getArray(String arr[], int n)
	{
	   Word[] words = new Word[n];
		
		for (int i=0; i<n ;i++)
		{
			words[i] =  new Word();
			String a =  arr[i];
			char[] A = a.toCharArray();
			Arrays.sort(A);
			a = (String.valueOf(A));
			
			words[i].string = a;
			words[i].index = i;
			
			
		}
		
		Stringss.sort(words, new mycomparator());
	for(int i=0; i<n; i++)
	{
		int in =  words[i].index;
		System.out.println(arr[in] +" "+ arr[i]);
	}
		
	}
	
	public static void main(String args[]) throws java.lang.Exception
	{
		Anagrams ang  =  new Anagrams();
		
		String[] arr =  {"cat", "dog", "tac", "god", "act"};
		ang.getStrings(arr,  arr.length);
		
		
	}
	
}
class mycomparator implements Comparator<Word>{
	
		public int compare(Word a, Word b)
		{
			return (a.string.compareTo(b.string))>0?1:-1;
		}
}
