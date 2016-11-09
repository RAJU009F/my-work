// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: min sub array with sum greater
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void swap(char *a,  char *b)
{
	char t= *a;
	*a = *b;
	*b = t;
	
}

void printPermationsUtil(char *str,  int l, int r)
{	int i;
	if(l==r)
	{printf("%s\n", str);
		}
	else
	{
		
		for(i=l; i<=r; i++)
		{
			swap((str+i), (str+l));
			printPermationsUtil(str, l+1, r);
			swap(str+i, (str+l));	
		}
		
		
	}
	
	
}

printPermations(char *str,  int n)
{
	
	printPermationsUtil(str, 0, n-1);
	
}

int main()
{
	char str[] = "ABC";
	printPermations(str, strlen(str));
}