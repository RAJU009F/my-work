#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
// finding the max sum in array
// find the sub sequence which forms the max sum in an array

int maxSum(int A[],int n)
	{
	int maxs=0;
	int currentsum= 0;
	int i;
	int st=0,end;
	int prev;
	for(i=0;i<n;i++)
	{
		prev = currentsum;
		currentsum +=A[i];
		if(currentsum< 0)
		{currentsum =0;
			st=i+1;
		}
		if(currentsum>maxs)
		{
			maxs = currentsum;
			end =i;
			}
	
	
	
	}
	
	for(i=st; i<=end;i++)
	{
		printf("\t%d",A[i]);
		
	}
	
	return maxs;
	
	
	}


int main()

	{
	
	int A[] = {-2,11,-4,13,-5,2};
	
	printf("max sum:: %d\n",maxSum(A, sizeof(A)/sizeof(A[0])));
	
	
	return 0;
	}