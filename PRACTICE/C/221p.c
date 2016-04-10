#include<stdio.h>
#include<stdlib.h>
void foo()
	{
		fork();
		if(fork()||fork())
			printf("Hello NAx\n");
	
	
	
	}
main()
	{
		foo();
	
	
	}
