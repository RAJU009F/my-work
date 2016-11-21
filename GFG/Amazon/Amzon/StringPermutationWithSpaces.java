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
# Topic or Type 	: GFG/Amazon
# Problem Statement	: Permutation with Spaces
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class StringPermutationWithSpaces
{
public  static  void permutewithSpacesUtil(char str[],  int i,  int  n, char buff[],  int j)
{
		if( i==n)
		{
			buff[j] = '\0';
			String s= buff.toString();
			System.out.print(s+" ");
			return;
			
		}else
			
			{
				buff[j] = str[i];
				permutewithSpacesUtil(str, i+1,  n, buff, j+1);
				buff[j] = ' ';
				buff[j+1] = str[i];
				permutewithSpacesUtil(str, i+1,  n, buff, j+2);
				
			}
	
	
	
}
public  static void permutewithSpaces(char str[])
{
	
	int n  =  str.length;
	
	char[]  buff  =  new char[2*n];
	buff[0] = str[0];
	permutewithSpacesUtil(str, 1,  n, buff, 1);
	
	
	
}

public static void main(String args[])
	{
	
		char str[] = {'A' , 'B', 'C'};
		
		permutewithSpaces(str);
	
	}


}