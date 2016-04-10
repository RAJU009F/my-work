#include<stdio.h>

main()
	{
	
		int i=20;
		
		const int  *p=&i;
		printf("%d\n",i);
		i=90;
		printf("%d\n",i);
		int j=10;
		
		p=&j;
		printf("%d\n",j);
		
		
		
		int m=60;
		
		int *const ptr1=&m;
		
		printf("%d\n",++m);
		int n=98;
	//	ptr1=&n;
	
	char *ptr="hello";
	ptr="nax";
	printf("%s\n",ptr);
		
	
	
	
	}
