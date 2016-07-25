// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: insert %20 instead of spaces in a string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void insertChar(char *str)
{
	
	int i = strlen(str)-1;
	int j = strlen(str)-1;
	while(str[i] == ' ')
			i--;
		
	while(i>=0)
	{
		if(str[i] == ' ')
		{
			str[j] = '0';
			str[j-1] = '2';
			str[j-2] = '%';
			j=j-3;
		}else
		{
			str[j] = str[i];
				j--;
		}
		i--;
		
		
	}
	
}


int main()
{
	
	char str[] = "Ind ian Histler    ";
	
	printf("Bfore: %s\n",str);
	insertChar(str);
	printf("After: %s\n",str);
	
	
	
}