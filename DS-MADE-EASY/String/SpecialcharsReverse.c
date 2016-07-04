#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/String
# Problem Statement	: Reverse the string without disturbing special chars
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

bool isAlpha(char ch)
{
	return (ch>=65 && ch<=90) || (ch>=97 && ch<=122);
	
	
}


void reverseUtil(char *str, int l, int r)

{
	while(l<r)
	{
		
		if(!isAlpha(str[l]))
			l++;
		else if(!isAlpha(str[r]))
			r--;
		else
		{
			str[l] ^=str[r];
			str[r] ^=str[l];
			str[l] ^=str[r];
			
			l++;
			r--;
		}
		
		
		
		
	}
	
	
	
	
}

void reverse(char *str)
{
	
	reverseUtil(str, 0, strlen(str)-1);
	
	
	
}


int main()
{
	
	
	char str[] = "I#ND4IA%N &HIT@L!LE^R* Gr32e#at$";
	printf("Before:%s\n", str);
	reverse(str);
	printf("After:%s\n",str);
	
}