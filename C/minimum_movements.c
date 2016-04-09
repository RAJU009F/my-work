#include<stdio.h>
#define N 9

int main()
	{
	int A[N];
	int i;
	int Wind=0, Sind=2, Bind=1;
	for(i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		
		
	}
	
	for(i=0; i<N; i++)
	{
		if(i+1%N==1 && A[Wind]<= A[i])
		{
			Wind = i;
			
		}
		
		if(i+1%N==0 && A[Sind]<= A[i])
		{
			Sind = i;
			
		}
		if(i+1%N==2 && A[Bind]<= A[i])
		{
			Bind = i;
			
		}
	}
	if (A[Wind]>A[Bind] && A[Wind] >A[Sind])
	{
		if( A[Bind] > A[Sind] )
			printf("WBS");
		else
			printf("WSB");	
		
	}else if(A[Wind]<A[Bind] && A[Bind] >A[Sind])
	{
		if( A[Wind] > A[Sind] )
			printf("BWS");
		else
			printf("BSW");
		
		
	}else
	{
		if( A[Wind] < A[Bind] )
			printf("SBW");
		else
			printf("SWB");
		
		
	}
		
		
		
		
		
	
	
	
	
	
	return 0;
	}