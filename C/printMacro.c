#include<stdio.h>

// Printing macro

#define PRINT(X) (#X)
int main()
{
		int a = 123;
	printf("\t%s\t",PRINT(123));
	
	
}