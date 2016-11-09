
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
# Topic or Type 	: GFG/ARRAY
# Problem Statement	:  check the given two strings are intereavings of third
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printInterLeavingsUtil(char *A,  char *B, char *C, int M, int N, int i)
{
	
	if(M==0 && N==0)
		printf("%s\n", C);
	if(M!=0)
	{
		C[i] = A[0];
		printInterLeavingsUtil(A+1,B, C, M-1,N, i+1 );
		
		
	}
	
	if(N!=0)
	{
		C[i] = B[0];
		printInterLeavingsUtil(A, B+1, C, M, N-1, i+1);
		
	}
	
	
}

void printInterLeavings(char *A, char *B, int M, int N)
{
	
	 char C[M+N+1];
	 C[M+N] = '\0';
	printInterLeavingsUtil(A, B, C, M, N, 0);
	
	
}
bool areInterLeavingsDynamic(char *a, char *b, char *c, int M, int N)
{
	
	bool IL[M+1][N+1];
	memset(IL, false, sizeof(IL));
	int i;
	int j;
	
	for(i=0; i<=M; i++)
		for(j=0; j<=N; j++)
		{
			if(i==0&&j==0)
				IL[i][j] = true;
			else if(i==0 && b[j-1]==c[i+j-1])
				IL[i][j] = IL[i][j-1];
			else if(j==0 && a[i-1]==c[i+j-1])
				IL[i][j] = IL[i-1][j];
			else if (a[i-1]==c[i+j-1] && b[j-1] != c[i+j-1])
				IL[i][j] = IL[i-1][j];
			else if (a[i-1]!=c[i+j-1] && b[j-1] == c[i+j-1])
				IL[i][j] = IL[i][j-1];
			else if (a[i-1]==c[i+j-1] && b[j-1] == c[i+j-1])
				IL[i][j] = IL[i-1][j]||IL[i][j-1];
			
			
			
		}
	
	return IL[M][N];
}

bool areInterLeavings(char *a, char *b, char *c)
{
	while(*c)
	{
		if(*a == *c)
			a++;
		else if(*b == *c)
			b++;
		else
			return false;
		
		
	}
		return !(*a||*b);		
	
	
}


int main()
{

	char *A = "ABC";
	char *B = "DBF";
	char *C= "ABDBFC";
	int M = strlen(A);
	int N = strlen(B);
	
	bool res= areInterLeavings(A, B, C);
	if(res)
		printf("Interleavings\n");
	else
		printf("Not Interleavings\n");
		
	res = areInterLeavingsDynamic(A, B, C,  M, N);
	if(res)
		printf("Interleavings\n");
	else
		printf("Not Interleavings\n");
	
	printInterLeavings(A, B, M, N);

}
