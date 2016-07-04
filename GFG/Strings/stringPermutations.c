#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Strings
# Problem Statement	: Generate all permutations of a string
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

void swap(char *a, char *b)
{
	char c = *a;
	*a = *b;
	*b = c;
	
	
}
void permutations(char str[], int l, int r)
{
	if(l==r)
	{	printf("%s\n",str);
		return;
	}
	int i;
	for(i=l; i<=r; i++)
	{
		swap((str+i), (str+l));
		permutations(str,l+1, r);
		swap((str+i), (str+l));
		
	}
	
	
}

int main()
{
	
	char str[] = "ABC";
	
	int n = strlen(str);
	
	permutations(str, 0 , n-1);
	
	
}