#include<stdio.h>
#include<stdlib.h>
void sort4(int *a,int n)
	{
		int l,m,h;
		
		m=0;l=0;
		h=n-1;
		int t;
		while(m<=h)
			{	
				switch(a[m])
					{
						case 0:
							t=a[l];
							a[l]=a[m];
							a[m]=t;
							
							l++;
							m++;
							break;
						case 1:
							m++;
							break;
						case 2:
							t=a[h];
							a[h]=a[m];
							a[m]=t;
							
							h--;
							break;	
					
					
					
					}
			
			
			
			
			}
			
	
	
	
	}
main()
	{
		int a[]={1,1,1,2,1,1,0,0,0,0,0,2,2,2,2,1,2,2,0};
	
		sort4(a,18);
		int i;
		for(i=0;i<18;i++)
			{
			
				printf("[%d]\t",a[i]);
			
			}
			printf("\n");
	
	}
