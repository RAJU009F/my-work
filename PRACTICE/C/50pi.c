#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char fun(char *a,int n)
	{
		return a[n];
	}

main()
{

char *a="nax"; 
int x;
  //x=(x & 0a0a0a0a0a)>>1 | (x&05050505)<<1 ;
  //x=(x&0c0c0c0c0c)>>2 | (x&03030303)<<2 ;
  x=(x&0f0f0f0f)>>4 | (x&f0f0f0f0)<<4 ;
  x=x&ffff0000)>>16| (x&0000ffff)<<16 ;

printf("%c\t\t%d\n\n",fun(a,6),x);


}
