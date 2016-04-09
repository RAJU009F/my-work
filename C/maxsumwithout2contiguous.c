#include<stdio.h>
#include<stdlib.h>

// Max without 2 contigous elemnts
int main()
	{
	
		int A[]={1,-3,4,-2,6,-1};
		int in=A[0];
		int ex=0;
		int temp;
		int i;
		int n= sizeof(A)/sizeof(A[0]);
		for(i=1;i<n;i++)
		{
			temp =in;
			in = ex + A[i];
			ex = temp>ex?temp:ex;
			
			
		}
	
	printf("Max withou contigous::%d", in>ex?in:ex);
	
	}