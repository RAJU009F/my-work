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
# Problem Statement	: Longest Ploindrome substring
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void countWords(char *str)
{
	int count =0;
	if(*str)
		count++;
	while(*str)
	{
		if(*str==' ' || *str=='\n' || *str=='\t')
		{	
			while(*str && *str==' ' || *str=='\n' || *str=='\t')
				str++;
			if(*str)
				count++;
		}
		str++;
		
	}
	
	printf("%d\n",count);
}
int main()
{

	char *sen = "I Lke you susmitha.  missing you alot";
	countWords(sen);

}