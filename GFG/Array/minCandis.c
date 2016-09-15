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
//using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: Dyanamic Progrming/ min Candis required
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
int minCandis(int rating[], int n)
{
	int candis_given[n] ;
	int i;
	for(i=0; i<n; i++)
		candis_given[i] = 1;
	
	for( i=1; i<n; i++)
		if(rating[i]>rating[i-1])
			candis_given[i] =candis_given[i-1]+1;
		
	for( i=n-2; i>=0; i--)
		if((rating[i]>rating[i+1]))
			if(!(candis_given[i]>candis_given[i+1]))
				candis_given[i] =candis_given[i+1]+1;
	
	int minC = 0;
	
	for(i=0;i<n; i++)
	{minC +=candis_given[i];}
	
	printf("Min NoOf Canids Required:%d\n",minC);
}


int main()
{
	int rating[] = {1,2,6,4,5,2,1};
	minCandis(rating, sizeof(rating)/sizeof(rating[0]));
	
}


