#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/String
# Problem Statement	: 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void buildLPS(int LPS[], char P[], int m)
{
	int i=1;
	int len =0;
	while(i<m)
	{
		if(P[i] == P[len])
		{
			len++;
			LPS[i] = len;
			i++;
		}else if( len>0)
			len = LPS[len-1];
		else
		{
			LPS[i] = 0;
			i++;
		}	
	}	
}
void KMP_Search(char P[], int m, char T[], int n)
{
	
	int LPS[m];
	buildLPS(LPS,P,m);
	int i=0;
	int j=0;
	while(i<n)
	{
		if(P[j]==T[i])
		{
			if(j==m-1)
			{
				printf("match found at %d\n",i-j);
				j=0;
			}else
			{
				i++;
				j++;				
			}

		}else if(j>0)
			j = LPS[j-1];
		else
			i++;
		
		
		
	}
	
	
	
}
int main()
{
	char P[] = "geeks";
	char T[] = "geeksforgeeks";
	KMP_Search(P, strlen(P),T, strlen(T));
	
	
	
}