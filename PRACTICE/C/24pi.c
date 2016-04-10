#include<stdio.h>
#include<stdlib.h>

int zero(int n)	
	{
		int count=0;
		if(!n)
			return -1;
		if(n==5)
			return 1;
			
		int i;
		for(i=5;n/i>=1;i*=5)
			{
				count +=n/i;
				printf("count=%d  i= %d\n\n",count,i);
			
			}		
			
		return count;	
	
	
	}

main()
	{
		int N;
		printf("Enter:");
		
		scanf("%d",&N);
		
		printf("N0 of Zeros: %d  \n\n",zero(N));
	
	}
