#include<stdio.h>
#include<stdlib.h>
void merge(int *a,int *b,int m, int n)
	{
		int i=m-1,j=n-1,k=m+n-1;
		printf("%d\n\n",k);
		while(i>=0 && j>=0)
			{
			
				if(a[i]>b[j])
				
					{
						a[k]=a[i];
						k--;
						i--;
					}
				else
					{
						a[k]=b[j];
						k--;
						j--;
					}
				//k--;		
			
			}
			
		
					
					
					while(j>=0)
						{
							a[k--]=b[j--];
							//k--;
						
						}
				
				
				
				
			
		
	
	
	
	
	}

main()
	{
		int a[14]={1,2,3,6,34,56,78};
		int b[]={3,5,7,27,33,55,90};
		int m=sizeof(a)/sizeof(a[0]);
		//printf("%d\n\n",m);
		int n=sizeof(b)/sizeof(b[0]);
		merge(a,b,7,n);
		int i;
		for(i=0;i<m+n;i++)
			{
				printf("[%d]\t",a[i]);
			}
	
	
	}
