import java.io.*;
import java.lang.*;
import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

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

bool test(char *a,  char *b)
{
	if(!*a && !*b)
		return true;
	else if(*a=='*' && *(a+1)!='\0' && *b=='\0')
		return false;
	else if(*a =='?' || *a==*b )
		return test(a+1, b+1);
	else if(*a=='*')
		return test(a+1, b) || test(a, b+1);
	return false;
	
}


int main()
{
	
	 test("g*ks", "geeks"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2
                             // instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
    
}