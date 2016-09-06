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
# Problem Statement	: max repeating number in a range of 0 to k
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


void maxrepeating(int arr[],  int n,  int k)
{
	int i;
	
	for(i=0; i<n; i++)
			arr[arr[i]%k] +=k;
	
	int max = arr[0];
	int r = 0;
	
	for(i=1; i<n; i++)
	{
		if(max<arr[i])
		{
			max = arr[i];
			r = i;
		}
		
	}
	
	printf("max : %d\n", r);
}
int main()
{
	int arr[] = {2, 3, 3, 5, 3, 4, 1, 7};
	maxrepeating(arr, sizeof(arr)/sizeof(arr[0]), 8);
	return 0;
}