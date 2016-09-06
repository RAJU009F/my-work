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
# Problem Statement	: min sub array with sum greater
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void smallestPositiveNum(int arr[],  int n)
{
	int res = 1;
	int i;
	for(i=0; i<n && res>=arr[i]; i++)
		res +=arr[i];
	
	printf("sum:: %d\n", res);	

}

int main()
{
	int arr[] = {1, 2, 5, 10, 20, 40};

	smallestPositiveNum(arr, sizeof(arr)/sizeof(arr[0]));

}