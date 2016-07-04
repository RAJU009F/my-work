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

void removeString(char *str1, char *str2)
{
	int count[256];
	int i;
	for(i=0;i<256;i++)
		count[i] = 0;
	
	for(i=0; *(str2+i);)
	{
		count[*(str2+i)]++;
		i++;
	}
	
	i=0;
	int j=0;
	
	while(*(str1+i))
	{
		if(count[*(str1+i)]==0)
		{
			*(str1+j) = *(str1+i);
			j++;
			//printf("%c",*(str1+i));
		}
			i++;	
	}
	
	*(str1+j) = '\0';
	
	
}


int main()
{
	
	char str1[] = "geeksforgeeks";
	char str2[] = "for";
	printf("Before::%s\n",str1);
	//printf("%s",str2);
	removeString(str1,str2);
	printf("After::%s\n",str1);
	
	
	return 0;	
}