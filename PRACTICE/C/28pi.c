#include<stdio.h>
#include<stdlib.h>
#include<string.h>


main()

	{
		char s[]="hello";
		char *p=(char *)malloc(10);
		
		strcpy(p,s);
		
		printf("%s",p);

	
	
	}
