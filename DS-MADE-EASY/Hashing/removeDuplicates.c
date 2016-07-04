#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Hashing
# Problem Statement	: remove the dulplicates from a string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

void removeDuplicates(char *str)
{
	int H[256];
	int i=0,j=0;
for(i=0;i<256;i++)
{	H[i] = 0;}

	i=0;
	while(*(str+i))
	{
		if(H[*(str+i)]==0)
		{
		*(str+j)= *(str+i);
			j++;
			
		}
		//printf("%c",str[j]);
		H[*(str+i)] = 1;
		i++;
	}
	
	str[j] = '\0';
	
	
}

int main()

{
	char str[] = "geeksforgeeks";
	
	printf("Before::\t%s\n",str);
	removeDuplicates(str);
	printf("After::\t%s\n",str);
	
	
	return 0;
}