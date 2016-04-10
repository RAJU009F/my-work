#include<stdio.h>
#include<stdlib.h>
int get(int a1[],int a2[],int l,int r,int n)
	{
		int i,j;
		
		if(l>r)
			return get(a2,a1,l,r,n);
			
		i=(l+r)/2;
		j=n-i-1;
		
		if(a1[i]>a2[j] && (j==n-1 || a1[i]<=a2[j+1]))
			{
				if(i==0 || a2[j]>a1[i-1])
					return (a1[i]+a2[j])/2;
					
				else
					return (a1[i]+a1[i-1])/2;	
			
			
			
			}		
		else if (a1[i]>a2[j] && j!=n-1 && a1[i]>a2[j+1])
			return get(a1,a2,l,i-1,n);
		else
				return get(a1,a2,i+1,r,n);	
	
	
	
	
	
	
	
	
	
	
	
	}
	
int getm(int a1[],int a2[],int n)
	{
	
		if(a1[n-1]<a2[0])
			return (a1[n-1]+a2[0])/2;
		if(a2[n-1]>a1[0])
			return (a1[n-1]+a2[0])/2;
		return get(a1,a2,0,n-1,n);
			
	
	
	
	}

main()
	{
		int a1[]={1,12,15,26,38};
		int a2[]={2,13,17,30,45};
		int n1=sizeof(a1)/sizeof(a1[0]);
		int n2=sizeof(a2)/sizeof(a2[0]);
		
		if(n1==n2)
			printf("%d\n\n",getm(a1,a2,n1));
		else
			printf("Doesn't Work\n\n");	
	
	
	
	}
