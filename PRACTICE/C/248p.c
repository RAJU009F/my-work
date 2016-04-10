#include<stdio.h>
#include<stdlib.h>

void print(int *a,int n)
	{
		int i;
		int max=0,c=0;
		for(i=0;i<n;)
			{
				if(a[i]+1==a[i+1])
					{
						i++;
						c++;
						if(max<c)
							max=c;
						
					
					}
				else
					{
						c=0;
			 			i++;
					
					
					
					}	
			
			
			}
			
		printf("[%d]\n\n",max+1);	
	
	
	
	}


main()
	{
		int a[]={1,2,3,4,5,67,67,45,3423,23,232,232,343};
		
		print(a,14);
	
	
	
	
	}
