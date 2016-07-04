#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/DP
# Problem Statement	: find maximum noof profit you get while traversing(top left to bottom right and  move right or down) in a 2-D array 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void getMaxProfit(int M[4][4], int m, int n)
{
	int P[m][n];
	int i,j;
	
	for(i=0;i<m;i++)
	{
		for(j=0; j<n;j++)
		{
			P[i][j] = M[i][j];
			
			if(j>0 && P[i][j]< M[i][j]+P[i][j-1])
					P[i][j]=M[i][j]+P[i][j-1];
				
			if(i>0 && P[i][j] < M[i][j] +P[i-1][j] )
					P[i][j] =  M[i][j] +P[i-1][j];
				
			if(i>0 && j>0 && P[i][j] < M[i][j] +P[i-1][j-1])	
					P[i][j] = M[i][j] +P[i-1][j-1];
			
			
			
		}
		
		
		
	}
	
	printf("Max Profit:: [%d]\n", P[3][3]);
}

int main()
{
	
	int M[][4] = {{1,0,3,5},
				{4,6,9,7},
				{9,3,5,8},
				{0,3,5,0}};
	
	getMaxProfit(M, 4, 4);
	
	return 0;
}

