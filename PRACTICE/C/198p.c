#include<stdio.h>

#include<stdlib.h>
int printset(int n)
	{
		int cnt=0;
		while(n)
			{
			cnt++;
			n=n&n-1;
			
			
			}
	
	
	
	
	}
main()
	{	
		int  n;
		printf("\n\nEnter N:\n\n");
		scanf("%d",&n);
		
		printf("No of bits set in[%d] is [%d]\n\n",n,printset(n));
	
	}
