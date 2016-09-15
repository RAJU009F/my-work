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
#include<map>
#include<vector>
using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: Frequency of a number
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void countFreq(int arr[], int l, int h,  vector<int> freq, int n)
{
	if(l<0 || h>=n)
		return;
	if(arr[l] == arr[h])
		{
			freq[arr[l]] += h-l+1;
		}else
		{
			int m = (h+l)/2;//+l;
			
			countFreq(arr, l, m, freq, n);
			countFreq(arr, m+1, h, freq, n);;
		
		}

}

int main()
{

	int arr[] = {};
	
	int n  =  sizeof(arr)/sizeof(arr[0]);
	
	vector<int> freq(arr[n-1]+1, 0);
	countFreq(arr, 0,  n-1, freq, n);
	
	for(int i=0; i<n; i++)
		cout<<"freq of "<<arr[i]<<" "<<freq[i];
	
}