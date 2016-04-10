#include<stdio.h>
#include<stdlib.h>

int Nways(int m,int n,int x)
	{
		if(x<1)
			return 0;
		if(n==1)
			return (x<=m);	
		
		int nways=0;
		int i=0;
		for(i;i<=m;i++)
			{
				nways+=Nways(m,n-1,x-1);
			
			
			}
		
	
		return nways;
	}

main()
	{
		printf("Nways:%d\n",Nways(6,2,4));
	
	}
