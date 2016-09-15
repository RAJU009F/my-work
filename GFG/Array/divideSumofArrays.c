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
// #include<map>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: Divide an array at an element into two sub arrys with equal sum
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printArray(int arr[],  int i,  int n)
{
	for(;i<n; i++)
		printf("%d ",arr[i]);
	
	printf("\n");
	
	
}
bool subArrays(int arr[],  int n)
{
	
	int sum =0;
	int i;
	for(i=0; i<n; i++)
		sum +=arr[i];
	
	int leftsum = 0;
	
	for(i=0; i<n; i++)
	{
		if(2*leftsum+arr[i] == sum)
		{
			printArray(arr, 0, i);
			printArray(arr, i+1, n);
			return true;
		}
		else
			leftsum +=arr[i];
		
		
	}
	return false;
}

int main()


{

	//int arr[] = {6, -2, -3, 2, 3};
	int arr[] = {6, -2, 3, 2, 3};
	//6, -2, 3, 2, 3
	bool res= subArrays(arr, sizeof(arr)/sizeof(arr[0]));
	if(res)
		printf(" equal sum sub arrays exists\n");
	else
		printf("equal sum sub arrays doesn't exists\n");
return 0;	
}