// import java.io.*;
// import java.lang.*;
// import java.util.*;

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
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Strings
# Problem Statement	: valid substring 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printMatchBrackets(char *str, int index, char *str out)
{
	if(index == strlen(str))
	{
		cout<<out<<endl;
	}else
	{
		int i;
		for(i=index; i<strlen(str); i++)
		{
			printMatchBrackets(str, i+1, out+"("+str.substr(index, i-index+1)+")");
		}
		
	}
	
	
	
}



int main()
{
	
	char *str = "abc";
	printMatchBrackets(str, 0, "");
	
	
	
}