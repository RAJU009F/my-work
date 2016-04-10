#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 256


void print(char *str)
	{
		int B[MAX]={0};
		int i=0;
		
		while(str[i]!='\0')
			{
				B[str[i++]]++;
				
			}	
		i=0;
		while(str[i]!='\0')
			if(B[str[i]]==1)
				printf("%c",str[i++]);
	
	}

main()
	{
		char s[]="hfkfs";
	
		
		print(s);
		
	
	
	}
