#include<stdio.h>
#include<stdlib.h>

int g(int i)
	{
	
		i=i++||i--&&i++;
		i>>1;
	
	}
	
int f(int a,int b)
	{
		return b==1?a:f(a,b-1)+a;
	
	}	
int m(int n)
	{
		return n==0?1:n*m(n=1);
	}
	
int c(int n)
	{
		return n==0?0:n+c(n-1);
	
	}	

main()
	{
		int a,b;
		if(b=((a=scanf("%d%d",&a,&b))?printf("beautiful:%d",a):printf("")))
			printf("%d",b);
		else
			printf("no w ay");	
			
		
		
	int x,y,z;
	x=(m(3),c(4),f(1,2));
	y=(c(100),f(x,x),m(5));
	z=(f(x,y),c(y),m(x));
	
	printf("%d  %d  %d",x,y,z);	
		
	
	
	}
