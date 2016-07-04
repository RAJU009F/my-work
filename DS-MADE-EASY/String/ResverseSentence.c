#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/String
# Problem Statement	: Reverse words in the given sentence
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void reverseUtil(char *str, int l,  int r)
{
	
	//int l=0;
	
	while(l<r)
	{
		str[l] ^=str[r];
		str[r] ^=str[l];
		str[l] ^=str[r];
		
		l++;
		r--;
	}
	
	
}

void reverse(char *str)
{
	reverseUtil(str, 0, strlen(str)-1);
	printf("intermediate reverse: %s\n",str);
	int st, end;
	int len = strlen(str);
	
	for(end=0; end<len; end++)
	{
		st = end;
		
		while(str[end] !=' ' && end <len)
			end++;
		
		reverseUtil(str, st, end-1);
		
	}
	
	
	
	
}


int main()
{
	char sent[] = "I am doing coding for the DSME problems";
	
	printf("Before Reverse:%s\n",sent);
	reverse(sent);
	printf("After Reverse:%s",sent);
	
return 0;	
}
