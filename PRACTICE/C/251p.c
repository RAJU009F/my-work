#include<stdio.h>
#include<stdlib.h>
int getsum(int n)
	{
		if(n>0)
			{
			
				return n+getsum(n-1);
			
			}
	
	
	}
int gcd(int a,int b)
	{
		if(a==0)
			return b;
		if(!b)
			return a;
			
		if(a>b)
			return gcd(a%b,b);
		else
			return gcd(a,b%a);			
	
	
	}	
	
	
int gcd1(int a,int b)
	{
		if(a==1 || b==1)
			return 1;
		if(a==b)
			return a;	
		if(a>b)
			return gcd1(a-b,b);
		else
			return gcd1(a,b-a);		
	
	
	}	
int lcm(int a,int b)
	{
		static int temp=1;
		if(temp%a==0 && temp%b==0)
			return temp;
	
		temp++;	
		lcm(a,b);
		
		return temp;		
	
	}	
int max(int *a,int n,int i,int m)
	{
		if(i<n)
		{
			if(m<a[i])
				{
					m=a[i];
				}
			 max(a,n,i+1,a[i]);
			
				//return max(a,n,i+1,m);	
	
		}	
		return m;	
	}		

void perfect(int n)
	{
			int i=1,k,m;
		while(i<=n)
			{	
				int j=1,sum=0; 
				while(j<i)
					{
						if(i%j==0)
							sum+=j;
						++j;	
					
					}
				if(sum==i)
					printf("[%d]\t",i);	
			
			
		
			
			i++;			
			
			}
	
	
	
	
	
	}

main()
	{
	
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	
	printf("%d\n",getsum(n));
	
	printf("gcd :%d\t %d \n\n",gcd(14,56),gcd1(14,56));
	printf("lcm:: %d \n\n",lcm(14,56));
	int A[]={1,2,3,4,5,6,7,8,9};
	printf("%d\n\n",max(A,9,0,-1));
	perfect(100000);
	
	
	}
