#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Hashing
# Problem Statement	: print first  repeated character
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void firstRepeatedChar(char *str)
{
	int i;
	int count[256];
	for(i=0; i<256; i++)
		count[i]=0;
	
	for(i=0; *(str+i);i++)
		count[*(str+i)]++;
	i=0;
	while(*(str+i))
	{
		
		if(count[*(str+i)]>1)
		{
			printf("%c",*(str+i));
			break;
		}
		count[*(str+i)]++;
		i++;		
	}
	
	
	
}


int main()
{
	char str[] = "geeksforgeeks";
	firstRepeatedChar(str);
return 0;
}
