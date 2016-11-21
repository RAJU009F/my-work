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
# Problem Statement	: FilterString
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void stringFilter(char *str)
{
	int n = strlen(str);
	int i=0;
	int j=0;
	
	while(j<n)
	{
		if(str[j]=='b')
			j++;
		else if(j<n-1&&str[j]=='a' && str[j+1]=='c')
			j +=2;
		else if(i>=0 && str[j]=='c' && str[i]=='a')
		{	i--;
			j++;
		}else
		{
			str[i] = str[j];
			j++;
			i++;
		}
		
		
		
		
	}
	str[i] = '\0';
		
	printf("%s\n", str);
	
	
}
int main()
{
	char str1[] = "ad";
    stringFilter(str1);
    
 
    char str2[] = "acbac";
    stringFilter(str2);
  
 
    char str3[] = "aaac";
    stringFilter(str3);
   
 
    char str4[] = "react";
    stringFilter(str4);
  
 
    char str5[] = "aa";
    stringFilter(str5);
 
 
    char str6[] = "ababaac";
    stringFilter(str6);

 



}