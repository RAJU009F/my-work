// HCF of two numbers
#include<stdio.h>

int hcf(int m, int n)
{
	if(m==n)
		return n;
	else if(m<=1 || n<=1)
			return 1;
	else if(m>n)
		return hcf(m-n,n);
 else
		return hcf(m, n-m);
	
	
	
}
int main()
	{
	int m, n;
	scanf("%d %d",&n,&m);
	printf(" HCF %d \n",hcf(m, n));
	
	
	
	}