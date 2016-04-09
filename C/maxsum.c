#include<stdio.h>
#include<stdlib.h>

int maxsum(int A[], int n)
	{
		int exc=0,  inc=0, old_inc;
		int i;
		for(i=0;i<n; i++)
			{
				old_inc = inc;
				inc = exc + A[i];
				exc = old_inc>exc?old_inc:exc;
				
			
			}
		
		return inc>exc?inc:exc;
	
	
	}

int main()
	{
		int A[] = {4,1,1,4,2,1};
		int size = sizeof(A)/sizeof(A[0]);
		printf(" %d " , maxsum(A, size) );
	
	
	}