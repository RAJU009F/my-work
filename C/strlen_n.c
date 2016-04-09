// Strings of N-Bits , array of size n

#include<stdio.h>
#define MAX 100
void Binary(int);
char A[MAX];
int main()
	{
	int n;
	
	scanf("%d",&n);
	Binary(n);
	}
	
void Binary(int n)
		{
			if (n<1)
				{
					printf("%s\n",A);
					return;
				}
				A[n-1]='a';
				Binary(n-1);
				A[n-1]='b';
				Binary(n-1);
				
		
		
		}