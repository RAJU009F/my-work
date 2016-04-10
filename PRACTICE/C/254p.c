#include<stdio.h>
#include<stdlib.h>
void change(int a[])
	{
		a[a[1]]=a[!a[1]];
	
	}
	
void change1(int a[])
	{
	
		a[a[0]]=a[!a[0]];
	
	}	
	
void change2(int a[])
	{
	
		a[!a[0]]=a[!a[1]];
	
	
	}	
void change3(int a[])
	{
		a[!a[1]]=a[!a[0]];
	
	
	}	
int sum(int m,int n)
	{
	
		return (printf("%*c%*c",m,' ',n,' '));
	
	
	}
	
int sum1(int m,int n)
	{
		char *c=(char *)m;
		
		return &c[n];
	
	
	}	

main()
	{
		int a[]={1,0};
		change(a);
		
		printf("a[0]=%d\ta[1]=%d\n\n\n",a[0],a[1]);
		change1(a);
		
		printf("a[0]=%d\ta[1]=%d\n\n\n",a[0],a[1]);
		change2(a);
		
		printf("a[0]=%d\ta[1]=%d\n\n\n",a[0],a[1]);
	
		
		change3(a);
		
		printf("a[0]=%d\ta[1]=%d",a[0],a[1]);
		
		printf("sum ==%d\n\n",sum(5,7));
		printf("sum==%d\n\n",sum1(5,7));
	}	
