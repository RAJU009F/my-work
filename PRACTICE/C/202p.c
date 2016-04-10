#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void my_cat(char *d,char *s)
	{
		return *d?my_cat(++d,s):(*d++=*s++)?my_cat(d,s):0;
	
	
	}
int cmp(char *a,char *b)
	{
		  return (*a == *b && *b == '\0')?1 : (*a == *b)? cmp(++a, ++b): 0;
	
	
	}

main()
	{
	
		char *a="indian";
		char *b="indian";
		//my_cat(a,b);
		
		printf("%s\n\n",a);
		
		if(cmp(a,b))
			printf("Equal\n\n");

		else
			printf("Not Equal:\n\n");		
	
	
	
	}
