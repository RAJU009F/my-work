#include<stdio.h>
#include<stdlib.h>
double t[1024];
double T(int n)
	{
		double sum=0;
		
		if(n<=1)
			return 2;
		int i;	
		for(i=1;i<n;i++)
			sum+=2*T(i)*T(i-1);
		
		return sum;		
	
	
	}
	
double tt(int n)
	{
		t[0]=t[1]=2;
		
		int i,j;
		
		for(i=2;i<=n;i++)
			{
				t[i]=0;
				for(j=1;j<i;j++)
					{
					
						t[i]+=2*t[j]*t[j-1];
					
					}
			
			}
	
	return t[n];
	
	}	
	
	
double t1(int n)
	{
		t[0]=t[1]=2;
		t[2]=2*t[0]*t[1];
		int i;
		for(i=3;i<=n;i++)
			{
				t[i]=t[i-1]+2*t[i-1]*t[i-2];
			
			}
			
		return t[n];	
	
	
	
	}	
	
void print(int a[],int n)
	{
		int i,j;
		int start=0,cursum=0,maxsum=0,maxstart,end;
			for(i=0;i<n;i++)
				
				{
					cursum+=a[i];
					
					if(cursum<=0)
						{
							cursum=0;
							start=i+1;
						
						
						}
					else if(cursum>maxsum)
						{
							maxsum=cursum;
							maxstart=start;
							
							end=i;
						
						
						}	
				
				
				
				}
				
			printf("sum::%d\n\n",maxsum);
			for(i=maxstart;i<=end;i++)
				{
					printf("[%d]",a[i]);
				
				}	
		
	
	
	
	}	
	
int maxcont(int a[],int n)
	{
		int M[n];
		int i;
		int maxsum=0;
		
		if(a[0]>0)
			M[0]=a[0];
		else
			M[0]=0;
			
		for(i=1;i<n;i++)
			{
				if(M[i-1]+a[i]>0)
					M[i]=M[i-1]+a[i];
				else
					M[i]=0;
			
			}		
		for(i=0;i<n;i++)
			{
				if(maxsum<M[i])
					maxsum=M[i];
			
			}
	
		printf("%d\n\n",maxsum);
	
	}	
	

main()
	{
		
		printf("sum::%lf\n\n",T(10));
		printf("sum::%lf\n\n",tt(10));
		printf("sum::%lf\n\n",t1(10));
		
		int a[]={-2,11,-4,13,-5,2};
		int n=sizeof(a)/sizeof(int);
		print(a,n);
		
		maxcont(a,n);
		
		
	
	
	
	}
