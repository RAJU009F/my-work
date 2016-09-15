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
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: count the noof pairs which make a pair
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
	
	unordered_map<int,  int> m;
	int i;
	for(i=0; i<n; i++)
		m[arr[i]]++;
	
	for(i=0; i<n; i++)
	{
		count_twice += m[sum-arr[i]];
		
		
		if(sum-arr[i] == arr[i])
			count_twice--;
	}
	
	cout<<"pairs"<<count_twice/2;
	
}



int main()
{
	int arr[] = {1, 5, 7, -1, 5};
	int sum = 6;
	count_pairs(arr,  sizeof(arr)/sizeof(arr[0]), sum);
	return 0;
}