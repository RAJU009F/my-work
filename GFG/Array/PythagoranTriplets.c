// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: circular Sub Array  sum
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printTriplets(int limit)
{
	
	int a,b,c=0;
	int m=2;
	int n;
	
	while(c<limit)
	{
		
		for(n=1; n<m; n++)
		{
			a = m*m - n*n;
			b = 2*m*n;
			c = m*m + n*n;
			
			if(c>limit)
				break;
			printf("%d %d %d\n", a, b, c);
		}
		m++;
		
	}
	
	
}


int main()
{
	
	printTriplets(20);
	
	
	return 0;
}