#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: 2D Array
# Problem Statement	: Mirroring of an array
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

void printMatrix(int M[3][3], int m, int n )
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0; j<n; j++)
		{
			
			printf("%d\t", M[i][j]);
			
		}
		printf("\n");
	}
	}
	
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b= t;
	
}	
void mirrorArray(int M[3][3], int m, int n)
{
	int i, j;
	
	for(i=0; i<m;i++)
	{
		for(j=i+1; j<n; j++)
			swap(&M[i][j], &M[j][i]);
		
	}
	
	
	
}	
	
	
//}


int main()
	{
	int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	printf("Matrix before\n");
	printMatrix(M,3,3);
	printf("Matrix After \n");
	mirrorArray(M,3,3);
	printMatrix(M,3,3);
	
	
	return 0;
	}