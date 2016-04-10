#include<stdio.h>
#include<stdlib.h>
int add(int m,int n)
	{
		char *c=(char *)m;
		return &c[n];
	
	
	
	}
int sum(int m,int n)
	{
		return printf("%*c%*c",m,' ',n,' '); 
	
	
	}	


main()
	{
		printf("add:::%d\n",add(23,56));
		printf("\nsum::%d\n\n",sum(23,56));
	
	
	}
