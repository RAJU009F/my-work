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
# Problem Statement	: missin number in duplicate arrays
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

int findMissingUtil(int arr1[],  int arr2[], int N)
{
	if(arr1[0]!=arr2[0])
		return arr1[0];
	if(N==1)
		return arr1[0];
	
	int l = 0;
	int h = N-1;
	int m;
	while(h>l)
	{
		m = (h-l)/2+l;
		
		if(arr1[m] == arr2[m])
			l = m;
		else
			h = m;
		
		if(l == h-1)
			break;
		
	}
	
	return arr1[h];
	
	
}


void findMissing(int arr1[],  int arr2[],  int M, int N)
{
	if(N==M-1)
		printf("missing Num %d", findMissingUtil(arr1, arr2, M));
	else if(M==N-1)
		printf("missing Num  %d", findMissingUtil( arr2,arr1, N));
	else
		printf("Invalid input");
	
	
	
	
}
int main()
{

	
	int arr1[] = {1, 4, 5, 7, 9};
    int arr2[] = {1, 5, 7, 9};
 
    int M = sizeof(arr1) / sizeof(int);
    int N = sizeof(arr2) / sizeof(int);
 
    findMissing(arr1, arr2, M, N);
	
	
	
}