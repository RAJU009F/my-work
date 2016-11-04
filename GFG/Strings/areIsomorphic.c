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
bool hashcode(char *str1, char *str2)
{
	
	int m = strlen(str1);
	int n = strlen(str2);
	
	
	
}

bool areIsomorphic(char *str1, char *str2)
{
	if(strlen(str1)!=strlen(str2))
		return false;
	return hashcode(str1) == hashcode(str2);

}

int main()
{
	bool res = areIsomorphic("", "");
	printf("%s", res?"Isomorphic":"Not Isomorphic");
	return 0;

}