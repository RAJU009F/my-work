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
# Problem Statement	: 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void modify(int arr[],  int index[],  int n)
{
		int i;
	for( i=0; i<n; i++)
		{
			index[index[i]] = arr[i];
		}
	for( i=0; i<n; i++)
	{
		arr[i] = index[i];
		index[i] = i;
	}

	
	for( i=0;i<n; i++)
		{
			printf("arr[%d]=%d ",i, arr[i]);
		}
		
		printf("\n");
	for( i=0;i<n; i++)
		{
			printf("arr[%d]=%d ",i, index[i]);
		}

}


int main()
{

	int arr[] = {50, 40, 70, 60, 90};
	int index[] = {3,  0,  4,  1,  2};
	
	modify(arr, index, sizeof(arr)/sizeof(arr[0]));
}
