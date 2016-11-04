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
# Topic or Type 	: GFG/Strings
# Problem Statement	: print all possible binaries 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printAll(char *str, int index, int n)
{
	if(index == n)
	{
		printf("%s\n", str);
	}else
	{
		if(str[index]=='?')
		{
			
			str[index] = '0';
			printAll(str, index+1, n);
			str[index] = '1';
			printAll(str, index+1, n);
			
		}
		
		else
		{
			printAll(str, index+1, n);
			
		}
	}
	
	
}

int main()
{
	char str[] = "?0";
	printAll(str, 0,  strlen(str));

}