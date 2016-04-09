#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void countSort(int *, int  , int );

int main()
	{
	
		int a[] = {1, 4, 1, 2, 7, 5, 2};
		int R=9,i, j,n;
		n= sizeof(a);
		countSort(a, R, sizeof(a));
		for(i=0;i<n;i++)
			{
			printf("\t[%d]",a[i]);
			}
	
	
	}
void countSort(int A[], int n , int R)
		{
			int out[n];
			int i;
			int count[R+1];
			memset(count, 0, sizeof(count));
			
			for(i=0; i<n ; i++)
				{
					++count[A[i]];
				}
			for(i=1; i<=R; i++)
				{
					count[i] += count[i-1];
				}
			for(i=0; i<n;i++)
			{	out[count[A[i]]-1] = A[i];
				--count[A[i]];
			}
			for(i=0;i<n;i++)
				{
				A[i] = out[i];
				}
		
		
		}