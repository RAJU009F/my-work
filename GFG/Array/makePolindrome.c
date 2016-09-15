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
# Problem Statement	: find the noof operations to make the array Ploindrome with only merge operations  
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


void makePolindrome(int arr[], int n)
{
	int i=0;
	int j=n-1;
	int ops =0;
	
	for(;i<=j;)
	{
		if(arr[i]==arr[j])
		{
			i++;
			j--;
		}else if(arr[i]>arr[j])
		{
			ops++;
			j--;
			arr[j] +=arr[j+1];
		}else
		{
			i++;
			arr[i] +=arr[i-1];
			ops++;
		}
			
	}
	
	
	printf("merge Operations req: %d\n",ops);
	
	
}
int main()
{
	
	
	
	int arr[] = {1, 4, 5, 9, 1};
	
	makePolindrome(arr, sizeof(arr)/sizeof(arr[0]));
}

