#include<stdio.h>
void f(int *);
int lcm(int a,int b)
	{
		static int t=1;
		if(t%a==0 && t%b==0)
			return t;
		else
			{
				++t;
				lcm(a,b);
			}		
	
	
	
	}
static int aa;	
static int aa;	
main()
	{
		int i=5;
		
		f(&i);
		printf("%d\n\n",i);
		
		
		int a[1]={13};
		printf("%d\n",0[a]);
		printf("\nLCM::%d\n",lcm(13,6));
		
		static int aa;
		
		
		char *ch2="fsdfsdf";
		char ch[]="\0";
		//ch2="fddf";
		ch2[2]='r';
		if(printf("%s",ch))
			printf("not Empty\t\n");
		else
			printf("Empty\t%s\n",ch2);	
		
		
		char c[]="%d\n";
		c[1]='v';
		printf(c,65);
	printf("%u\t%s\n",&"Hello",&"Hello");
		
	
	
	
	}
	
void f(int *j)
	{
		 static int s=1;
		 
		 if(*j)
			{
				s=s * *j;
				*j=*j-1;
				f(j);
			
			}	
		*j=s;	
	
	}	
	
	
