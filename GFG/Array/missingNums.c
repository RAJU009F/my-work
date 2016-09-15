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
# Problem Statement	: Missing numbers using avg 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void missing_nums_using_avg(int arr[],  int n)
{
	int Totalsum = (n)*(n+1)/2;
	int i=0;
	for(i=0; i<n-2; i++)
			Totalsum -=arr[i];
		
	int avg = Totalsum/2;
	
	int a= avg*(avg+1)/2;
	int b= n*(n+1)/2-a;
	for(i=0;i<n-2; i++)
	{
		if(avg<arr[i])
			b -=arr[i];
		if(avg>=arr[i])
			a -=arr[i]; 
	}
	
	printf("%d %d", a, b);
}


void missing_nums(int arr[],  int n)
{
	int x = 0;
	int i,a=0,b=0;
	for( i=0; i<n-2; i++)
		 x ^=arr[i];
	 
	for(i=1; i<=n; i++)
			x ^=i;
	 int set_bit = x &~(x-1);
	 
	 
	 
	 for(i=0; i<n-2; i++)
	 {
		 if(arr[i]&set_bit)
			 a ^=arr[i];
		 else
			 b ^=arr[i];
		 
	 }
	 
	 
	 for(i=1; i<=n; i++)
	 {
		 if(i&set_bit)
			 a ^=i;
		 else
			 b ^=i;
		 
	 }
	 printf("%d %d\n", a, b);
	 
	
	
	
}

int main()
{

int arr[] = {1, 3, 5, 6};

int n=sizeof(arr)/sizeof(arr[0]);

missing_nums(arr, n+2);
missing_nums_using_avg(arr, n+2);

}