#include<stdio.h>

int rev(int N)

{
	int rev=0;
	while(N)
	{
		rev  = rev*10+(N%10);
		N = N/10;	
		
	}
	
	return rev;
	
}
int revr(int N)
{
	
	int rev = 0;
	return N==0?0:(N%10)+rev*10+revr(N/10);

	
	
}
int main()
	{
	int N, n;
	int i;
	int sum;
	int k=20; printf("%d%d%d%d",k,k++,++k,k);
	scanf("%d",&N);
	
	printf("%d\n\n",rev(N));
	printf("%d\n",revr(N));
	for(sum=0,scanf("%d",&n);n;sum=sum*10+n%10,n=n/10);
		printf("%d",sum);
	
	}