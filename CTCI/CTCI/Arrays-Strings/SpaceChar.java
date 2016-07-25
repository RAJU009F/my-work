import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: insert %20 instead of spaces in a string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class SpaceChar
{
	public static String insertSpaceChar(String str)
	{
		char[] arr = str.toCharArray();
		int i = arr.length-1;
		while(arr[i] == ' ')
		i--;
		int j = arr.length-1;
		while(i>=0)
		{
				if(arr[i]!=' ' )
					{
					arr[j] = (char)arr[i];
					j--;
					}
				else{
					
					arr[j-0] = (char)'0';
					arr[j-1] = (char)'2';
					arr[j-2] = (char)'%';
					j = j-2;
				}				
					
			i--;
		}
		
		
		return  arr.toString(); 
		
	}




public static void main(String args[])
	{
		String str = "Ind ian Histler    ";
		System.out.println("Before : "+str);
		str = insertSpaceChar(str);
		System.out.println("After : "+str);
		
	
	}

}