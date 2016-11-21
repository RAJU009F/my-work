// import java.lang.*;
// import java.util.*;
// import java.io.*;

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
// #include<queue>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	:  WildCard Pattern Matching
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/

int match(char *pattern, char *text)
	{
		if(*pattern == '\0')
				return 1;
		if(*text=='\0')
				return *pattern == '*'||*pattern=='\0';
		if(*pattern == '?' || *pattern == *text )
				return match(pattern+1, text+1);
		if(*pattern == '*')
				return match(pattern+1, text) || match(pattern ,text+1);
		//if(*pattern !=*text)
				return 0;
				
	
	
	
	}
bool wildmatchDP(char *pattern, char *text)
{
	int m =  strlen(pattern);
	int n =  strlen(text);
	if(m==0)
		return n==0;
	printf ("m= %d n= %d", m, n );
	bool lookup[n+1][m+1];
	int i, j;
	memset(lookup, false, sizeof(lookup));
	lookup[0][0]= true;
	for( j=1; j<=m; j++)
	{
		if(pattern[j-1] == '*')
				lookup[0][j]= lookup[0][j-1];
	}
	
	for( i=1; i<=n; i++)
	{
		for( j=1; j<=m; j++)
		{
			if(pattern[j-1] =='*')
				lookup[i][j] = lookup[i][j-1] || lookup[i-1][j];
			else if(pattern[j-1] == '?'||pattern[j-1] == text[i-1])
					lookup [i][j] = lookup[i-1][j-1];
			else
				lookup[i][j] = false;
			
		}
		
		
		
	}
	printf("%d", lookup[n][m]);
	return  lookup[n][m];
}
	

int main()
	{
		char pattern[] = "baaabab";
		char text[] = "*****ba*****ab";
		// char pattern[] = "a*a";
	wildmatchDP(pattern, text)? printf("Matched"):printf("Not matched") ;
	
	}