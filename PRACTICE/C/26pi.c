#include<stdio.h>
#include<stdlib.h>
int count(int *a,int m,int n)
	{
		if(n==0)
			return 1;
		if(m<=0 && n>=1)
			return 0;
		if(n<0)
			return 0;
			
		return count(a,m-1,n)+count(a,m,n-a[m-1]);			
	
	
	
	}

main()
	{
		int i,j;
		int a[]={1,2,3};
		printf("\n\nNo of possible ways:: %d \n\n",count(a,3,4));
	
	}
