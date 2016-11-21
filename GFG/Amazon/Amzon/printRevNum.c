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
# Topic or Type 	: GFG/Amazon
# Problem Statement	: max repeat number
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

unsigned int printRevNum(int n)
	{
		unsigned  int rev  = 0;
		int i;
		for(i=0; i<32; i++)
			{
				if(n&(1<<i))
					{
						rev |= (1<<(32-1-i)); 
					}
			}
			
			return rev;
			
	
	}

int main()
	{
		
		int n = 1;
		printf("%u\n", printRevNum(n));
		printf("%u\n", printRevNum(5));
	
	
	}