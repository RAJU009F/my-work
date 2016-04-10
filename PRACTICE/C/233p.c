#include<stdio.h>
#include<stdlib.h>

void print(int m[][3])
	{
		int i=0,j=0;
		for(i;i<3;i++)
			{
				printf("[ ");
				for(j=0;j<3;j++)
					printf("%d\t",m[i][j]);
				printf("]\n");	
			
			}
			
	
	}
void trans(int m[][3],int n)
	{
		int i,j;
		for(i=n-1;i>0;i--)
			{
				for(j=n-1;j>=i;j--)
					{
						int t=m[i][j];
						m[i][j]=m[j][i];
						m[j][i]=t;
					
					}
			
			}
	
	
	}
		
	
main()
	{
		int M[3][3];
		
		printf("Enter Elems:\n\n");
		int i,j;
		for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)					
						scanf("%d",&M[i][j]);
			
			}
			
		printf("Actual MAT::\n\n");		
		print(M);
		trans(M,3);
		printf("Trans MT::\n\n");
		print(M);
	
	
	}
