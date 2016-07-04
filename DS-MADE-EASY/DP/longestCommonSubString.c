#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/DP
# Problem Statement	: find the longest common sub string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void print(char *s1, char *s2, int i, int j, int n)
{
	int k;
	
	printf("Lenght of longest SubString::%d\nsubString::",n);
	for(k=i-n+1; k<=i; k++)
		printf("%c",s1[k]);
	
	
	
	
	
}
void longestCommonSubString(char *s1, char *s2)

{
	
	int m=strlen(s1);
	int n = strlen(s2);
	int LCS[m][n];
	int length=0;
	int m_i,m_j;
	int i, j;
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			LCS[i][j] = 0;
			
			if(s1[i]==s2[j])
			{
				if(i==0 || j==0)
					LCS[i][j] = 1;
				else	
					LCS[i][j] = LCS[i-1][j-1]+1;
				if(length<LCS[i][j])
				{
					length = LCS[i][j];
					m_i = i;
					m_j = j;
				}
			}
			
			
		}
		
		
	}
	
	
	print(s1, s2, m_i, m_j, length);
}



int main()
{

char *s1="Geeksforgeeks";
char *s2="geeksquiz";

longestCommonSubString(s1, s2);




}