#include<stdio.h>
#include<stdlib.h>
#define b(x) x/4
int nways(int x,int y)
	{
	
	
		if((x==5) && (y==5))
			return 1;
		if(x>5 || y>5)
			return 0;	
			
		else
			return (nways(x+1,y)+nways(x,y+1));
				
	
	
	
	}
main()
	{
		printf("WAYS::%d\n\n",nways(0,0));
	
	printf("%d\n\n",64/b(4));
	
	}
