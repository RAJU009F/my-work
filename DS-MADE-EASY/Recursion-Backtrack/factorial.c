#include<stdio.h>
#include<stdlib.h>

// Example to find Factorial of a number 'n'

int fact(int n)
	{
		if(n<=1)
			return 1;
		else
			return n*fact(n-1);
	
	
	
	}

int main()
	{
		int n=9;
		int i;
		for(i=0; i<n; i++)
			{
				printf("\tfact(%d) is: %d\n", i, fact(i));
			}
	
	
	}