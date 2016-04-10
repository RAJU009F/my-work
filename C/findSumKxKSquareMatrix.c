#include<stdio.h>
#include<stdlib.h>
// find the k x k square matrix sum in a nxn matrix

// time complexity: O(k^2n^2)
void findKxKSum(int M[5][5], int n, int k)
{
	int i, j ,p,q,sum;
	
	if(k>n)
		return ;
	for(i=0; i<n-k+1; i++)
	{
		for(j=0;j<n-k+1; j++)
		{
			sum=0;
			for(p=i;p<k+i;p++)
			{
				for(q=j;q<k+j;q++)
						sum +=M[p][q];
				
			}
			printf("%d \t",sum);
			
			
		}
		printf("\n");
		
		
	}
	
	
	
	
}


int main()
	{
	int k=3, n=5;	
	int M[5][5] ={{1, 1, 1, 1, 1},
                     {2, 2, 2, 2, 2},
                     {3, 3, 3, 3, 3},
                     {4, 4, 4, 4, 4},
                     {5, 5, 5, 5, 5},};
	
	findKxKSum(M, n, k);
	return 0;
	}
