#include<stdio.h>

int add(int a, int b)
	{
	
	return (printf("%*c%*c",a,'\r',b,'\r'));
	
	}
int main()
	{
		int i=1;
		int a=10,b=9,r;
		 i = ++i/i++;
		 printf("%d\n",i);
		 
		 r = printf("addition : %d", add(a, b));
	
	}
	