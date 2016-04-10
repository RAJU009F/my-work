#include<stdio.h>
#include<stdlib.h>
int Nways(int m, int n,int x)
	{
		if(x<1)
			return 0;
		if(n==1)
			return (x<=m);
		int i,nw=0;
		
		for(i=1;i<=m;i++)
			nw+=Nways(m,n-1,x-i);
			
		return nw;			
	
	
	
	}
main()
	{
		printf("Nways(6,2,10):%d\n",Nways(4,3,5));
		printf("Nways(6,2,):%d\n",Nways(6,2,4));
	
	}
