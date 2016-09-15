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
# Problem Statement	: find the noof operations to ameke the target array zero 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

int operations(int arr[],  int n)
{
	int result = 0;
	int i;
	
	while(true)
	{
		int z_count=0;
		for(i=0; i<n ;i++)
		{
			if(arr[i]&1)
				break;
			if(arr[i]==0)
				z_count++;
			
		}
		
		if(z_count == n)
			return  result;
		
		if(i==n)
		{
		int j;
			for(j=0; j<n; j++)
			{
				arr[j] = arr[j]/2;
				
			}
			result++;
			
		}
		
		int j ;
		
		for(j=i;j<n;j++)
		{
			if(arr[j]&1)
			{
				result++;
				arr[j]--;
			}
			
		}
		
		
	}
	
	
}


int main()
{

int arr[] ={16, 16, 16, 8};

printf("Noof operations: %d", operations(arr, sizeof(arr)/sizeof(arr[0])));
}