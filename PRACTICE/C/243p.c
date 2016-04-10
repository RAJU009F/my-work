#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

int haspair(int *a,int x,int n)
	{
		bool B[MAX]={0};
		int i;
		for(i=0;i<n;i++)
			{
				if(x-a[i]>=0 && B[x-a[i]]==1)
					return 1;
				else
					B[a[i]]=1;	
			
			
			}
		return 0;
	
	}

main()
	{
		int a[]={11,34,56,78,2,46,67,89,6,83};
		
			if(haspair(a,9,10))
				printf("\n\nit has pair::\n\n");
			else
				printf("No pair\n\n");			
	
	
	}
