#include<stdio.h>
#include<stdlib.h>


int totalPaths(int A[2][2], int n, int M, int N,  int count)

	{
	
	
	if(0==M && 0==N)
		{
			count++;
			return count;
		}
			if(N>0 && A[M][N-1] !=0)
				{count = totalPaths(A, n, M, N-1, count);}
	
			if(M>0 && A[M-1][N] !=0)
				{count = totalPaths(A, n, M-1, N,count);}
			
		return count;
	
	}
	
	int main()
	{
	
		int A[3][3] ={{1,0,0},{1,1,0},{0,1,1}};
		int size = 2;
		printf("%d", totalPaths(A, 3, 2,2,0));
	
	}
