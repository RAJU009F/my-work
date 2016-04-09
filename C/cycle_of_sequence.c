#include<stdio.h>

int cyclelen(int n)
{
	
	if (n==1)
		return 1;
	else if(n%2==0)
			return 1+cyclelen(n/2);
	else
			return 1+cyclelen(3*n+1);
	
}
int main()
	{
	
	int x, y;
	int i, max=0, temp;
	scanf("%d %d", &x, &y);
	
	for(i=x; i<=y; i++)
		{
			temp = cyclelen(i);
			if(max < temp)
				max = temp;
		
		}
	
	printf("%d",max);
	
	}