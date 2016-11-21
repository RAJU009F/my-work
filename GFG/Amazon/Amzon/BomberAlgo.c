

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
# Problem Statement	: Kth element in spiral print
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
------------
*/

char *bomberAlgoImple(char *input, int len)
{
	if(input == '\0')
		return '\0';

	
	int i =0 ;
	int j = 0;
	while(j<len-1)
	{
		
		if(input[j] == input[j+1] )
				j = j+1;
		else if (i>0&&input[i-1] ==input[j])	
			{		i = i-1;
					j = j+1;
			}
		else
		{
			input[i] = input[j];
			i++;
			j++;
		}
		
		
	}
	input[i] = '\0';
	
 return input;
}

	int main()
	{
		char str[]  = "aabcccdee";
		
		printf("%s", bomberAlgoImple(str, strlen(str)));
		
		return 0;
	}