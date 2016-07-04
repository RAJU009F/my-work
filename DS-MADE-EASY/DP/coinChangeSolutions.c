#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/DP
# Problem Statement	: noof solutions possible to make  change of N
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

int countSolutions(int s[], int m, int V)
{
	if(V==0)
		return 1;
	if(V<0)
		return 0;
	if(V>0 && m<0)
		return 0;
	
	return (countSolutions(s, m, V-s[m]) + countSolutions(s, m-1, V));
	
	
	
}

int countSolutionsDP(int s[], int m, int V)
{
	int count[V+1];
	memset(count, 0, sizeof(count));
	int i, j;
	count[0]=1;
	for( i=0; i<=m; i++)
	{
		for(j=s[i]; j<=V; j++ )
			count[j] +=count[j-s[i]];
		
		
	}
	
	return count[V];
	
	
	
}



int main()
{

int s[] ={1,2,3,4};
int m = sizeof(s)/sizeof(s[0]);

printf("Possible Solutions are :: [%d]\n",countSolutions(s,m-1, 10));

printf("Possible Solutions are uing DP:: [%d]\n",countSolutionsDP(s,m-1, 10));

return 0;
}