// Strings of lenght n drawn from 0...k

#include<stdio.h>

void kStrings(int , int);
char A[100];
int main()

{

int n, k;
scanf("%d",&n);
scanf("%d",&k);
kStrings(n, k);
return 0;


}

void kStrings(int n, int k)
	{
		int i;
		if (n<1)
			{
			
			printf("%s",A);
			return;
			}
		for( i=0; i<k; i++)
			{
				A[n-1] = (char)i;
				kStrings(n-1,k);
			}
	}