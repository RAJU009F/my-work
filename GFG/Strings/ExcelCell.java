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

void reverse(char *str, int r)

{
		int i=0;
		while(i<r)
		{
			*(str+i) ^= *(str+r);
			*(str+i) ^= *(str+r);
			*(str+i) ^= *(str+r);
			
		}
	
}

void findColumn(int n)
{
	
	char column[50];
	int i=0;
	while(n>0)
	{
		
		int rem = n%26;
		if(rem==0)
		{
			column[i++] = 'Z';
		   n= n/26-1;
		}else
		{
			column[i++] = rem-1+'A';
			n = n/26;
		}
		
		
	}
	
	reverse(column ,i-1);
	printf("%s", column);
}

int main()
{
	
	findColumn(2000000);
	findColumn(52);
	findColumn(45);
	findColumn(32424324324);
	
	
}