// import java.util.*;
// import java.lang.*;
// import java.io.*;

// #!/usr/bin/python -O

#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include<stdbool.h>
 #include<limits.h>

// # // #include<iostream>
// # // #include<algorithm>
// # // #include<string>
// # // #include<vector>
// # // using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Stacks
# Problem Statement	: Find the first position to make the path circular  
# Description		: 
# Complexity		: 
# =======================
# sample output
# ----------------------

# =======================
*/

// Petro pump 
struct PP
{
		int petrol;
		int dist;
	
	
	
};

int  findtheCircle(struct PP arr[],  int n)

{
	
	
	int start =0 ;
	int end =1;
	int cur_petrol = arr[start].petrol-arr[start].dist;
	while((start != end) || cur_petrol<0)
	{
		
		// remove the pp  from start
		while((start !=end) && cur_petrol<0 )
		{
			
			cur_petrol -= arr[start].petrol - arr[start].dist;
			start = (start+1)%n;
			
			// if circular path doesn't possible i.e. in case start reaches same position
			if(start==0)
				return -1;
		}
		
		cur_petrol += arr[end].petrol - arr[end].dist; 
		end  =  (end+1)%n;
	}
	
	return start;
	
}

int main()
{


struct PP arr[] = {{6, 4}, {3, 6}, {7, 3}};

int res = findtheCircle(arr,  sizeof(arr)/sizeof(arr[0]));

(res == -1)?printf("Not possible"):printf("cirtculrt path : %d", res);
}