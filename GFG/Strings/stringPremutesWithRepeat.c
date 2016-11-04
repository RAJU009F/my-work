
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
# Problem Statement	: string permutes with repeat
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void permuteWithRepeatsUtil(char *str, char *data, int index, int last )
{
	int i;
	int len = strlen(str);
	
	for(i=0; i<len ; i++)
	{
		data[index] = str[i];
		if(index==last)
		{
			printf("%s\n", data);
			// return;
		}
		else	
		permuteWithRepeatsUtil(str, data, index+1, last);
	}
	
	
}
void permuteWithRepeats(char *str, int n)
{
	char *data = (char *)malloc(sizeof(n+1));
	data[n] = '\0';
	permuteWithRepeatsUtil(str, data, 0, n-1);
	
	
}

int main()
{
	
	char *str="ABC";
	
	permuteWithRepeats(str, strlen(str));
	printf("sizeof:%d, srlen:%d", sizeof(str), strlen(str));
	
}
