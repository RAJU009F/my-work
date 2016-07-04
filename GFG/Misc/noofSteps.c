#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Misc
# Problem Statement	:  nof of steps req to reach destination
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

int steps(int source, int step, int dest)
{
	if(abs(source)>dest)
		return INT_MAX;
	if(source == dest)
			return step;
	int pos = steps(source+step+1, step+1, dest);
	int neg = steps(source-step-1, step+1, dest);
	
	return pos>neg?neg:pos;
	
}

int main()
{
	int dest = 11;
	printf("Number of steps req::%d",steps(0,0,dest));
	
	
	
}


