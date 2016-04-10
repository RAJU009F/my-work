#include<stdlib.h>
#include<stdio.h>
static int diff;
void maxd(int a[],int l ,int h)
	{	
		if(l>h)
			return;
		if(l==h)
			return;
			
		else
			{
			
			
						int mid=l+(h-l)/2;
						if(a[mid]>a[l])
							{
								if((mid-l)>diff)
									diff=mid-l;			
							
							
							
							}
							
						if(a[mid]<a[h])
							{
								if(h-mid>diff)
									diff=h-diff;
							
							
							
							
							}	
						if(a[l]<a[h])
							{
								if(h-l>diff)
									diff=h-l;
							
							
							
							
							}
						maxd(a,l,h-1);
						maxd(a,l+1,h);	
					
					
					
					
					
					
					
				
			
			
			
			
			
			
			
			
			
			}		
	
	
	}


main()	
	{
	
		int a[]={65,23,12,43,33,13,67,78,54,21};
		int m=sizeof(a)/sizeof(a[0]);
		m=m-1;
		
		maxd(a,0,m);
	
		printf("\nMax Diff:: is:: %d \n\n",diff);
	
	
	
	
	
	}
