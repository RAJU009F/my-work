// print sum
#include<stdio.h>
int sumofDigits(int num)
{
	
	return num ==0 ? 0: (num%10)+sumofDigits(num/10);
	
}

int main()
	{
	int num;
	int sum;
	for(scanf("%d",&num),sum=0; num;sum+=num%10,num/=10);
	printf("\t\tsum::%d\n",sum);
	scanf("%d",&num);
	printf("\tsumofdigits:%d\n\n",sumofDigits(num));
	
	}