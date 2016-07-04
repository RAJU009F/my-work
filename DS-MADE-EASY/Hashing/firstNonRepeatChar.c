#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Hashing
# Problem Statement	: print first non repeated character
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void printFirstNonRepeat(char str[])
{
	int count[256],i,j;
	for(i=0;i<256;i++)
		count[i] =0;
	i=0,j=0;
	while(*(str+i))
	{
		count[*(str+i)]++;
		i++;
		
		
	}
	
	i=0;
	while(*(str+i))
	{
		if(count[*(str+i)]==1)
		{printf("first non repeated char::%c\n", *(str+i));
	
		return;}
		i++;
	}
	
	printf("no non repeated char found in :%s\n",str);
	
}

int main()
{
	
	char str[] = "geeksforgeeks";
	
	printFirstNonRepeat(str);
	
	
	
	
}