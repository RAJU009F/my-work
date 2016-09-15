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
# Problem Statement	: active and inactive cells after k dayas 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void active_inactive(int arr[], int n, int k)
{
	int t[n];
	int i;
	for(i=0; i<n; i++)
		t[i] = arr[i];
	
	while(k--)
	{
		t[0] = 0^arr[1];
		t[n-1] = arr[n-2]^0;
		
		for(i=1; i<=n-2; i++)
			t[i] = arr[i-1]^arr[i+1];
		
		for(i=0;i<n;i++)
			arr[i]=t[i];
		
		
		
	}
	
	int act=0, inact=0;
	for(i=0; i<n; i++)
		arr[i]?act++:inact++;
	
	printf("active: %d , inactive: %d", act, inact);
	
}


int main()
{
	int arr[] = {0, 1, 0, 1, 0, 1, 0, 1};
	
	int n  =  sizeof(arr)/sizeof(arr[0]);
	active_inactive(arr, n, 3);


}