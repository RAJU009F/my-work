#include<stdio.h>
#define NIL -1
#define MAX 100
int lookup[MAX];

void _init1()
	{
		int i;
		
		for(i=0;i<MAX;i++)
			lookup[i]=NIL;	
	}
int fib1(int n)
	{
		if(lookup[n]==NIL)
			{
				if(n<=1)
					lookup[n]=n;
				else
					lookup[n]=fib1(n-1)+fib1(n-2);	
			
			
			}
			
			return lookup[n];
	
	
	}

int fib(int n)
	{
		unsigned int f[n+1];
		f[0]=0;
		f[1]=1;
		int i;
	
		for(i=2;i<=n;i++)
			{
				f[i]=f[i-1]+f[i-2];
			}
		return f[n];
	
	
	}
main()
	{	
		int N;
		printf("Enter the N:");
		scanf("%d",&N);
		
		printf("fib:%d\n",fib(N));
		
		_init1( N);
		printf("fib1:%d\n",fib1(N));


	}


