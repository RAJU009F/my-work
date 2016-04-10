#include<stdio.h>
#include<stdlib.h>
void print(int b[],int );

main()
	{
		
	
	int a[]={2,5,6,88,4344,6778,34333};
	int b[13]={1,3,4,90,654,667};
	
		combine(a,b,7,6);
		
		print(b,13);
	
	
	}
void combine(int a[],int b[],int m,int n)
	{
		
		int i=m-1;
		int j=n-1;
		
		int k=i+j+1;
		
		while(i>=0 && j>=0 )
			{
				if(a[i]>=b[j])
					{
						b[k]=a[i];
						i--;
					
					}
				else
					{
						b[k]=b[j];
						j--;
					
					}	
				k--;
			
			
			}
			
			while(i>-1)
				{
					b[k]=a[i];
					k--;
					i--;
				}	
			while(j>-1)
				{
					b[k]=b[j];
					j--;
					k--;
				
				}	
	
	
	
	}	
	
	
void print(int b[],int m)
	{
		int i=0;
		
		
		for(i;i<m;i++)
			{
				printf("[%d]\t",b[i]);
			
			}
	
	
	}	
