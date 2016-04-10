#include<stdio.h>
#include<stdlib.h>

int pascal(int n,int k)
	{
		
	
		if(n==0)
			return 0;
			
		if(k==n || k==1)
			return 1;
			
		if(k==0)
			return 1;
			
		if(n>1)
			return pascal(n-1,k)+pascal(n-1,k-1);
						
	
	
	}


main()
	{
		int n=2,i;
		for(i=0;i<=n;i++)
		{
			printf("{%d]\t",pascal(n,i));
	
	}
	
	}
