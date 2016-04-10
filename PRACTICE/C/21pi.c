#include<stdio.h>
#include<stdlib.h>


main()
	{
		int a[]={-2, 11, -4, 13, -5, -2};
		int s=sizeof(a)/sizeof(a[0]);
		int i,j;
		int maxindex=0;
		int start=0;
		int sum=a[0];
		int cur=0;
		int maxstart;
		for(i=0;i<s;i++)
			{
				cur=cur+a[i];
				if(cur<=0)
					{
						start=i+1;
						cur=0;
						
					
					
					}
					
				else
					{
						if(cur>sum)
							{
								sum=cur;
								maxindex=i;
								maxstart=start;
							
							
							}
					
					}	
			
			
			
			}
			
		for(i=maxstart;i<=maxindex;i++)
			{
				printf("[%d]\t",a[i]);
				
			
			
			
			}	
		printf("\n\n\n");	
		
	
	
	}
