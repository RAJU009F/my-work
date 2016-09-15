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
# Problem Statement	: max prod sub array
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void maxProd(int arr[],  int n)
{
	int max_so_far = INT_MIN;
	int cur_max = 1;
	int cur_min = 1;
	int i;
	for(i=0; i<n; i++)
	{
		if(arr[i]>0)
			cur_max = cur_max*arr[i];
		else if(arr[i]==0)
		{
			cur_max = 1;
			cur_min = 1;
		}else
		{
			int t = cur_max;
			cur_max = 1 > cur_min*arr[i]?1:cur_min*arr[i];
			cur_min = cur_min < t*arr[i]?cur_min:t*arr[i];
			
			max_so_far = max_so_far>cur_max?max_so_far:cur_max;
		}
		
		
		
	}
	
	printf("max prod %d", max_so_far>cur_max?max_so_far:cur_max );
	
}



int main()
{
	int arr[] = {-1, -2, -3, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	maxProd(arr, n);

}