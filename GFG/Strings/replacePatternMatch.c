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
# Problem Statement	: Replace matched pattern word with X 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void replacePattern(char *str, char *pattern)
{
	int n =  strlen(str);
	int m = strlen(pattern);
	int i=0;
	int j=0;
	while(str[i])
	{
		int p =0;
		while(j<n && p<m &&str[j] == pattern[p])
		{
			p++;
			j++;
		}
		
		if(p==m)
		{
			if(i>=1&&str[i-1]=='X')
				continue;
			else
			{str[i] = 'X';
				i++;}
			
		}else
		{
			j = j-p;
			str[i] = str[j];
			i++;
			j++;
		}
		
	}
	
	str[i] = '\0';
	printf("%s", str);
}

int main()
{

	char str[] = "GeeksGeeks";
	
	replacePattern(str, "Geeks");


}