#include<stdio.h>
#include<stdlib.h>
#define N 350 
int B[17];
void count(int *a,int n)
	{
		int i,j;
		int c[N];
		
		for(i=0;i<N;i++)
			c[i]=0;
		for(i=0;i<n;i++)
			c[a[i]]=c[a[i]]+1;
			
		for(i=1;i<N;i++)
			c[i]=c[i]+c[i-1];
			
		for(i=0;i<n;i++)
			B[c[a[i]]]=a[i];
			c[a[i]]=c[a[i]]-1;			
		
	
	
	
	}
main()
	{
		int A[17]={12,34,5,6,7,89,34,56,78,89,234,34,46,345,232,232,34};
		
		count(A,17);
		int i,n=17;
		
		for(i=0;i<n;i++)
			{
				printf("[%d]\t",B[i]);
			
			
			}
		printf("\n\n");	
	
	
	
	}
