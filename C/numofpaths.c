#include<stdio.h>
#include<stdlib.h>


int totalPaths(int A[3][3], int n, int M, int N, int row, int col, int count)

	{
	
	//if (col > )
	if (col==N-1 && row==M-1)
			return 1;
	
	if (col<n && row<n)
	{
	 if(A[row][col]==1)
			return totalPaths( A,  n,  M,  N,  row,  col+1,  count) + totalPaths( A,  n,  M,  N,  row+1,  col,  count);
	
	else if(A[row][col]==0)
			return 0;
	}
	else
	{return 0;}
	
	/*if(row==M && col ==N)
		{
			count++;
			return count;
		}
			if(col<N && A[row][col] !=0)
				{count = totalPaths(A, n, M, N, row, col+1, count);}
	
			if(row<M && A[row][col] !=0)
				{count = totalPaths(A, n, M, N, row+1, col, count);}
			
		return count;*/
	
	}
	
	int main()
	{
	
		int A[3][3] ={{1,0,0},{1,1,1},{1,1,1}};
		int n = 3;
		printf("%d", totalPaths(A, n, 3,3, 0,0,0));
	
	}
