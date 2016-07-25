// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: CTCI
# Problem Statement	: insert %20 instead of spaces in a string
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/



bool isCompressable(char *str)
{
	char last  = str[0];
	int count = 1;
	int size = 0;
	int i;
	char temp[5];
	//printf("%d",strlen(str));
	for( i=1; i<strlen(str); i++)
	{
		
		if(last == str[i])
		{
			count++;
			//printf("count:%d",count);
		}else
		{
			
			sprintf(temp, "%d", count);
			size += 1+strlen(temp);
			last = str[i];
			count = 1;
			//printf("size::%d\n",size);
		}
		
		sprintf(temp, "%d",count);
		size += 1+strlen(temp);
		
	}
	
	
	return size > strlen(str);
	
}
char  *compress(char *str)
{
	int len =  strlen(str);
	
	if(!isCompressable(str))
			return; 
	//printf("dfsf");
	char last  = str[0];
	int count = 1;
	int size = 0;
	int index =0;
	char temp[5];
	int i;
	for( i=1; i<strlen(str); i++)
	{
		
		if(last == str[i])
		{
			count++;			
		}
		else
		{			
			if(count ==1)
			{				
				str[index] = (char)last;
					index++;
			}else{	
				
				sprintf(temp,"%d", count);
				size += 1+strlen(temp);
				str[index] = (char)last;
				index++;
				int j=0;
				for(; *(temp+j); j++, index++)
					str[index] = temp[j];
						
			}
			last = str[i];
				count = 1;	
		}

	}
	
	if(count ==1)
			{
				
				str[index] = (char)last;
				index++;
			}else
			{	
				sprintf(temp, "%d",count);
				size += 1+strlen(temp);
				str[index] = (char)last;
				index ++;
				int j=0;
				//int j=0;
				for(; *(temp+j); j++, index++)
					str[index] = temp[j];
			}	
			str[index] = '\0';
	
return str;

}


int main()
{
	char str[] ="AAAAABBBBMCCCDDDEEEK";
	printf("Before: %s\n", str);
	printf("%s\n",compress(str));
	//printf("After: %s\n", str);
	
	
return 0;

}