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
bool isDigit(char ch)
{
	
	return (ch>=48 && ch<=57);
}

void printSum(char *str)
{
	int res = 0;
	
	int i=0;
	
	while(str[i])
	{	
		if(isDigit(str[i])){
			int ind = 0;
			while(isDigit(str[i]))
			{
				ind =  ind*10 + str[i] - '0';
				i++;
			}
			res +=ind;}
		else
		i++;
	}
	
	
	printf("sum:: %d\n", res);
	
	
}


int main()
{
	printSum("1abc23");
	printSum("1abc2x30yz67");
	
	
}