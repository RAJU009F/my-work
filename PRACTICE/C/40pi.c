#include<stdio.h>
#include<stdlib.h>
int cat(int n)	
	{
		if(n==0)
			return 1;
		int count=0;
		
		int i;
		for(i=1;i<=n;i++)
			{
				count+=cat(i-1)*cat(n-i);
			
			}
			
		return count;	
	
	
	
	}

main()
	{
		printf("catalan number::%d\n\n",cat(3));
	
	
	
	
	}
