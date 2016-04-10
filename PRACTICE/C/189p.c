#include<stdio.h>
char *g1()

	{
		static char c[1024]="fdfgd";
		
		return c;
	
	}
main()
	{
		char *g="SF";
		strcpy(g1(),g);
		//printf("%s",g1());
		g=g1();
		strcpy(g,"hkhfsd");
		printf("%s\n",g);
		
	
	}
