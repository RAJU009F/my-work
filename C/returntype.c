// return type of scanf

#include<stdio.h>

int main()
{
	int a;
	char c[10];
	printf("%d",scanf("%s  %d",c,&a));
	int *p=malloc(sizeof(int)) ;
	*p = 12;
	printf("%d",*p);
	
	return 0;
}