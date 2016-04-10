#include<stdio.h>
#include<stdlib.h>
int subset(int a[],int n,int x)
	{
		int m[n+1][x+1];
		int i,j;
		m[0][0]=0;
		for(i=0;i<=x;i++)
			m[0][i]=0;
	
		for(i=1;i<=n;i++)
			{
				for(j=0;j<=x;j++)
					{
					m[i][j]=m[i-1][j]||m[i-1][j]-a[i];			
					
					
					}
					
					
			
			
			
			
			}
		return m[n][x];	
	
	}
	
int issubset(int a[],int n,int x)
	{
		if(x==0)
			return 1;
			
		if(n==0 && x)
			return 0;
			if(a[n-1]>x)
				return issubset(a,n-1,x);
				
			return issubset(a,n-1,x)|| issubset(a,n-1,x-a[n-1]);	
			
				
	
	
	
	}	
main()
	{
		int a[]={3,2,4,19,3,7,13,10,6,11};
		int n=sizeof(a)/sizeof(int);
		if(subset(a,n,17)>0)
			printf("YES:::\n\n");
			
		if(issubset(a,n,17))
			printf("YES::\n\n\n");	
	
	
	
	}
