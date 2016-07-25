
// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: Reverse the given string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void reverse(char *str)
{
	int i=0; 
	int j = strlen(str)-1;
	while(i<j)
	{
		str[i] ^= str[j];
		str[j] ^= str[i];
		str[i] ^= str[j];
		i++;
		j--;
	}
	
	//return str;
}

int main()
{
	char str[] = "ABCD";
	printf("%s\n", str);
	reverse(str );
	
	printf("\n%s ", str);
	
	return 0;
}