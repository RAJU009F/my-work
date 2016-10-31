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
# Topic or Type 	: GFG/BT
# Problem Statement	: find the height of the tree given their indexs
# Description		: 
# Complexity		: 
=======================
#steps:
=----------------


#sample output
----------------------

=======================
*/

void findDepth(int arr[], int depth[], int i)
{
	if(depth[i])
		return;
	if(arr[i]==-1)
	{
		depth[i] = 1;
		return;
	}
	if(depth[arr[i]] == 0)
		findDepth(arr, depth, arr[i]);
	
	depth[i] = depth[arr[i]] + 1;
	
}

void findHeight(int arr[],  int n)
{
	int depth[n];
	int i;
	for(i=0;i<n; i++)
		depth[i] = 0;
		
		for(i=0; i<n; i++)
			findDepth(arr, depth,i);
	
	int max=INT_MIN;
	for(i=0; i<n; i++)
		if(max<depth[i])
			max = depth[i];
	printf("max depth: %d\n", max);	
	
}


int main()
	{
	
		 //int parent[] = {1, 5, 5, 2, 2, -1, 3};
		int parent[] = {-1, 0, 0, 1, 1, 3, 5};
		
		findHeight(parent, sizeof(parent)/ sizeof(parent[0]));
	return 0;
	
	}