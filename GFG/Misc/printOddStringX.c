#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Misc
# Problem Statement	:  print Odd length string in X format
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


void printX(char *str)
{
	int i,j,x;
	int n= strlen(str);
	for(i=0,j=n-1; i<n&&j>=0; i++,j--)
	{
		if(i<j)
		{
			for(x=0; x<i; x++)
				printf(" ");
			printf("%c",str[i]);
			
			for(x=0; x<j-i-1; x++)
				printf(" ");
			printf("%c",str[j]);
			
			
			
			
		}
		if(i==j){
			for(x=0;x<i;x++)
				printf(" ");
		printf("%c",str[i]);}
		else if(i>j)
		{
			for(x=0; x<=j-1; x++)
				printf(" ");
			printf("%c",str[j]);
			
			for(x=i-j-1; x>=0; x--)
				printf(" ");
			printf("%c",str[i]);
			
			
			
		}
		
		
		
		
		printf("\n");
	}
	
	
}


int main()
{
	
	char str[] = "geeksfOrgeeks";
	printX(str);
	
	
}