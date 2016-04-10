#include<stdio.h>
#include "237p.c"
extern int a[10];
int gcd(int m,int n)
	{
		if(m==0)
			return n;
		if(n==0)
			return m;
			
		if(m>n)
			return gcd(m%n,n);
		else
			return gcd(m,n%m);	
	
	
	}

main()
	{
		a[0]=10;
		printf("%d\n",a[0]);
		int d[3][2][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
		
		
	printf("%d\n",gcd(6,12));	
	}
