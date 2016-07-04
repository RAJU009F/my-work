#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/DP
# Problem Statement	: minimum noof coins required to make N
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

int minCoins(int s[], int m , int V)
{
	int res= INT_MAX;
	
	if(V==0)
			return 0;
	int i;
	for(i=0; i<m; i++)
	{
		if(s[m]<=V)
		{
			int sub_res = minCoins(s, m, V-s[i]);
			if(sub_res != INT_MAX && sub_res+1 <res)
				res = sub_res+1;
			
		}
		
		
	}
	return res;
	
	
	
	
}


int main()
{
	
	int s[] ={1,2,3};
	int m = sizeof(s)/sizeof(s[0]);
	printf("Minimum noof coins req: [ %d ]\n",minCoins(s, m, 5));	
	return 0;
}