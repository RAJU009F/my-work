#include<stdio.h>
#include<limits.h>


int matrixChainorder(int p[], int l, int n)
{
	
	if (l==n)
		return 0;
	int k, min = INT_MAX, count;

	for(k=l; k<n; k++)
	{
		count = matrixChainorder(p, l, k)+matrixChainorder(p,k+1,n) +p[l-1]*p[k]*p[n];
		if(min>count)
			min = count;
		
	}
	
	return min;
	
	
}
int main()
{
	    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

	printf("%d \n\n", matrixChainorder(arr,1,n-1));
	
	return 0;
}