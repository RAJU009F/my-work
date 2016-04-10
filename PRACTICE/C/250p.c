#include<stdio.h>
#include<stdlib.h>
#define MAX 3

void rotate(int a[][MAX])
	{
		int i,j;
		for(i=0;i<MAX;i++)
			{
			for(j=i;j<MAX;j++)
				{
					if(i!=j)
						{
						a[i][j]^=a[j][i];
						a[j][i]^=a[i][j];
						a[i][j]^=a[j][i];	
				
						}
				
				
				}
			
			
			}
			
		for(i=0;i<MAX/2;i++)
			{
				for(j=0;j<MAX;j++)
					{
						a[j][i]^=a[j][MAX-1-i];
						a[j][MAX-1-i]^=a[j][i];
						a[j][i]^=a[j][MAX-1-i];
						
					
					
					
					
					}
			
			
			
			
			
			}	
	
	
	
	
	}
void display(int a[][MAX])
	{
		int i,j;
		for(i=0;i<MAX;i++)
			{	
				printf("\n[ ");
				for(j=0;j<MAX;j++)
					{
						printf(" %d  ",a[i][j]);
					
					
					
					}
					
					printf("  ]\n");
			
			
			}
	
	
	}
	
void shift(int *a,int k,int n)
	{
		int i;
		int t[k];
		for(i=0;i<k;i++)
			{
				t[i]=a[i];
			
			
			}
			
		for(i=0;i<n;i++)
			{
				a[i]=a[i+k];
			
			
			}	
		for(i=0;i<k;i++)
			{
			a[n-k-1+i]=t[i];
			
			}
	
	
	
	
	
	
	
	
	}	
	
void shift1(int a[],int n)
	{
		
		int t=a[0],i;
		for(i=0;i<n-1;i++)
			{
				a[i]=a[i+1];
			
			}
			a[i]=t;
		
	
	
	
	
	
	
	
	
	
	}	
	
int max(int *a,int i,int m)
	{
		if(m<a[i])
			return max(a,i+1,a[i]);
		else
			return max(a,i+1,m);	
	
	
	}	
main()
	{
	
		int a[MAX][MAX]={1,2,3,4,5,6,7,8,9};
		
		int A[]={1,2,3,4,5,6,7,8,9};
		display(a);
		rotate(a);	
		
		display(a);
		
		shift(A,3,10);
		int i;
		for(i=0;i<9;i++)
			{
			
			printf("[%d]\t",A[i]);
			
			}
		for(i=0;i<3;i++)
			shift1(A,10);
	
		for(i=0;i<9;i++)
			{
			
			printf("[%d]\t",A[i]);
			
			}
			
		printf("%d\n\n",max(A,0,-9999));	
	
	}
	
	
