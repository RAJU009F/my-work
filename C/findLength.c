#include<stdio.h>
#include<stdlib.h>

int minimum(int a, int b)
	{
		return a<b? a:b;
	}
int maximum(int a, int b)
	{
	
		return a>b?a:b;
	}
int find_lenght_longest_consecutives(int A[], int n)
	{
		int length=1;
		int i, j;
		
		for(i=0; i<n-1; i++)
			{
			
				int min = A[i], max = A[i];
				for(j=i+1; j<n; j++)
					{
						
						min = minimum(min, A[j]);
						max = maximum(max, A[j]);
						if(max- min == j-i)
							{
								length = maximum(length, max-min+1 );
							}
					
					
					}
			
			}
	
	return length;
	
	
	}

int main()
	{
		int A[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
		int size = sizeof(A)/sizeof(A[0]);
		printf("%d", find_lenght_longest_consecutives(A, size));
		return 0;
	}