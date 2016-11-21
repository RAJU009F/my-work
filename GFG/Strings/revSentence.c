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
# Problem Statement	: Rev words in a sentence
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void reverse(char *str, int i, int j)
{
	while(i<j)
	{
		*(str+i) ^=*(str+j); 
		*(str+j) ^=*(str+i);
		*(str+i) ^=*(str+j);
		i++;
		j--;
	}
	
	
}

void reverseS(char *str, int len)
{
	reverse(str, 0, len-1);
	*(str+len) = '\0';
	printf("%s\n",str);
	int i=0;
	int start =0;
	int end =0 ;
	
	while(*(str+i) )
	{
		start  = i;
		while(*(str+i) !='\0' && *(str+i)!=' ')
		{
			i++;
		}
		reverse(str, start, i-1);
		printf("%s\n",str);
		i++;
		
		
	}
	//*(str+i) ='\0';
	
}

int main()
{
	char str[] = "I love you Susmitha";
	printf("Before Rev:%s\n", str);
	reverseS(str, strlen(str));
	printf("After reverse: %s\n", str);

}