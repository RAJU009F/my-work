#include<stdio.h>
#include<stdlib.h>
#define my_sizeof(x) (char *)(&x+1)-(char *)(&x)
int main()

{
	
	int a;
	printf("\t size is %d\n",my_sizeof(a));
	
	return 0;
}