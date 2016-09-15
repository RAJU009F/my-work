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
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

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

void count_pairs(int arr[],  int n, int sum)
{
	
	int count_twice = 0;
	
	unordered_map<int,  int > map;
	
	for(int i=0; i<n; i++)
		map[arr[i]]++;
	
	for(i=0; i<n; i++)
	{
		count_twice += map[sum-arr[i]];
		
		
		if(sum-arr[i] == arr[i])
			count_twice--;
	}
	
	printf("%d", count_twice/2);
	
}



int main()
{
	int arr[] = {1, 5, 7, -1, 5}
	int sum = 6;
 count_pairs(arr,  sizeof(arr)/sizeof(arr[0]), sum);
}