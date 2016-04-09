#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool checkoneNode(int A[], int size)
{
	int i;
	
	for(i=0; i<size-1; i++)
	{
		int x = A[i] - A[size-1];
		int y = A[i] - A[i+1];
		if(x*y<0)
			return false;
		
	}
	return true;
	
	
	
}
bool checkoneNode1(int A[], int size)
{
	
	int min , max, i;

		if(A[size-1]>A[size-2])
		{min = A[size-2];
		max = A[size-1];}
		else{
			max = A[size-2];
		min= A[size-1];
		}	
for(i=0;i<size-2;i++)
{
	if(A[i]<min)
			min = A[i];
	else if(A[i] > max)
			max = A[i];
	else	
			return false;
	
	
}
return true;	
	
}

int main()
	{
	
	int A[] = {50,20,30,25};//{50,20,10,30,60};
	
	checkoneNode(A, sizeof(A)/sizeof(A[0]))?printf("Yes"):printf("No");
	checkoneNode1(A, sizeof(A)/sizeof(A[0]))?printf("Yes"):printf("No");
	
	
	}