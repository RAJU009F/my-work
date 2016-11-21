// import java.lang.*;
// import java.util.*;
// import java.io.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: Print all possible strings
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/

void printStringsUtil(char str[],  int i,  int j,  int n, char out[])
{
	if(i==n)
	{
		out[j] = '\0';
		cout<< out<<"$";
		return;
	}
	
	out[j] = str[i];
	printStringsUtil(str, i+1, j+1, n, out);
	out[j] = ' ';
	out[j+1] = str[i];
	printStringsUtil(str, i+1, j+2, n, out);
	
	
	
}
void printStrings(char str[])
	{
		int n  = sizeof(str)/sizeof(str[0]);
		
		char out[2*n];
		out[0] = str[0];
		printStringsUtil(str, 1, 1, n, out );
		
	
	}
int main()
	{
	
		char str[] = "ABC";
		
	printStrings(str);
	}