//LCS
#include<stdio.h>

int LCS(int *, int);
int M[100];
int main()
{

int a[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
int size = sizeof(a)/sizeof(a[0]);
int result = LCS(a, size);
printf("\n\n\t%d\n",result);
return 0;
}

int LCS(int A[], int size)
	{
		M[0] = A[0];
		M[1] = A[1]>A[0]?A[1]: A[0];
		int i;
		for(i=2;i<size;i++)
		{
			M[i] = (M[i-2] + A[i])>M[i-1]?M[i-2]+A[i]:M[i-1];
		
		}
	return M[size-1];
	
	
	}