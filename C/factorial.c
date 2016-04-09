// Factorial 
#include<stdio.h>

int Fact(int );
int main()
	{
	int N, R;
	scanf("%d",&N);
	R = Fact(N);
	printf("Factorial of %d is:: %d\n",N, R);
	
	return 0;
	}
int Fact(int N)
	{
		if(N==0 || N==1)
			return 1;
		else
			return N*Fact(N-1);
	
	
	
	}