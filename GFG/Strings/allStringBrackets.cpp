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
# Problem Statement	: print all the strings with bracket seperated.
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printMatchBrackets(string str, int index, string out)
{
	if(index == (str.length()))
	{
		cout<<out<<endl;
	}else
	{
		int i;
		for(i=index; i<(str.length()); i++)
		{
			printMatchBrackets(str, i+1, out+"("+str.substr(index, i-index+1)+")");
		}
		
	}
	
	
	
}



int main()
{
	
string str= "abcd";
	printMatchBrackets(str, 0, "");
	
	
	
}