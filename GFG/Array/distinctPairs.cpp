// import java.io.*;
// import java.lang.*;
// import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

#include<iostream>

//#include<bits/std++.h>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: find the noof pairs in an array  
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void noofPairs(int arr[],  int n)
{
	int right=0;
	int left = 0;
	vector<bool> visited(n,false);
	int count =0;
	while(right<n)
	{
		
		while(right<n && !visited[arr[right]])
		{
			count += right-left;
			visited[arr[right]] = true;
			right++;
		}
		
		while(left<right&& right!=n && visited[arr[left]])
		{
			visited[arr[left]] = false;
			left++;
		}
	
		
		
	}
	
	cout<<count;
	
}

int main()
{
	 int arr[] = {1, 4, 2, 4, 3, 2};


	noofPairs(arr, sizeof(arr)/sizeof(arr[0]));

}