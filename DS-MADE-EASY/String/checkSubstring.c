#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/String
# Problem Statement	: Verify wheather its a substring or not
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printSubString(char *P, int n,  char *S, int m)
{
	int i,j;
	for(i=0;i<(n-m+1);i++)
	{
		j=0;
		while(j<m && P[i+j]==S[j])
		j++;
			
		if(j==m)
		{
			printf("\nPattern Matched at :: %d\n",i);
		}

		
	}
	
	
	
	
}

int main()

{
char P[] = "geeksforgeeks";
char S[] = "geeks";
printSubString(P, strlen(P), S, strlen(S));

return 0;
}