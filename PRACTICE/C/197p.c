#include<stdio.h>
#include<stdlib.h>
int size(int a)
	{
	
		return ((char *)(&a+1)-(char *)&a);
	
	}



main()
	{
		int a;
		
		printf("size of:%d\n\n",size(a));
	
	
	
	
	
	}
