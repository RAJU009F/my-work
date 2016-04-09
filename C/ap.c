#include<stdio.h>

int findmissing(int a[], int l,int h, int diff)
{
	if(l>h)
			return -1;
	if(l==h)
			return a[l];
	int m = l+(h-l)/2;	
		
	if((a[m]==a[0]+m*diff) && (a[m+1]-a[m])!=diff	)
			return a[m]+diff;
	 if((a[m]==a[0]+m*diff) && (a[m+1]-a[m])==diff)
			return findmissing( a,  m+1, h, diff);
	if((a[m]!=a[0]+m*diff))
			return findmissing(a,l ,m-1, diff);
	
	
	
}


int main()
	{
	
	int a[] = {2,4,6, 8, 10, 14};
	int n = sizeof(a)/sizeof(a[0]);
	int diff = (a[n-1]-a[0])/n;
	printf("%d",findmissing(a, 0, n-1, diff));
	
	return 0;
	}