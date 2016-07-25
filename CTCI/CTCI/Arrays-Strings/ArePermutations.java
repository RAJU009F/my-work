import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: check wheather two given strings are permutations or not
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class ArePermutations
{
	public static boolean arePermutations(String s1, String s2)
	{
		s1  = s1+s1;
		
		return s1.contains(s2);
		
		
	}
	
	public static void main(String args[])
	{
		
		String s1 = "ABCDEF";
		String s2 = "DEFABC";
		
		if(arePermutations(s1, s2))
			System.out.println("Permutations");
		else
			System.out.println("Not Permutations");	
		
		
		
		
	}
	
	
}