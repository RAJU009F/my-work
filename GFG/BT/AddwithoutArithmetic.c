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
# Topic or Type 	: GFG/BT
# Problem Statement	:  Stock Span Problem
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/

int add(int a, int b)
	{
		if(b==0)
			return a;
		int newa = a^b;
		printf("newa : %d\n", newa);
		int newb = (a&b)<<1;
		printf("newb : %d\n", newb);
		return add(newa, newb);	
	
	}


int main()
	{
	
		int a  = 5;
		int b =  4;
		
		printf("%d \n", add(a, b));
	
	}