#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int l,int lh,int h)
	{
		int t[h-l+1];
		int i=l;
		int j=lh;
		int k=lh+1;
		int r=h;
		int k1=0;
		
		while(i<=lh && k<=h)
			{
				if(a[i]>a[k])
					{
						t[k1++]=a[k++];	
					
					}
				else
					{
						t[k1++]=a[i++];
					}
			
			
			
			}
		while(i<=lh)
			{
				t[k1++]=a[i++];
				
			
			
			}
		while(k<=h)
			{
				t[k1++]=a[k++];
			
			}
			
		k1--;		
		for(k1;k1>=0;k1--)
			{
				a[h--]=t[k1];
			
			
			}
	
	
	
	
	}

void mergesort(int a[],int l,int h)
	{
		if(l<h)
			{
				int m=l+(h-l)/2;
				
				mergesort(a,l,m);
				mergesort(a,m+1,h);
				
				merge(a,l,m,h);
			
			
			
			}
	
	
	
	}
	
void print(int a[],int n)
	{
		int i;
		for(i=0;i<=n;i++)
			{
				printf("[%d]\t",a[i]);
			
			}
	
	
	
	}	

main()
	{
		int a[]={34,56,3,1,687,44,6767,23,67,32};
		int size=sizeof(a)/sizeof(int);
		mergesort(a,0,size-1);
		print(a,size-1);
	
	}
