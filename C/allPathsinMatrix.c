#include<stdio.h>
#include<stdlib.h>
// print all paths from top left to bottom right 
void printAllPaths(int A[2][3], int i, int j ,int m, int n, int path[16], int p)
	{
		if(i==m-1)
			{
				int k;
				for(k=j; k<n;k++)
					{
							path[p] = A[i][k];
							p++;
					}
				for(k=0;k<p;k++)
						printf("%d\t",path[k]);
				printf("\n");
				//printf("row");
				return;
			
			
			}
			
		if(j==n-1)
		{
			
			int k ;
			for(k=i;k<m;k++)
			{
				path[p] = A[k][j];
				p++;
			}
			
			for(k=0;k<p;k++)
			{
				printf("%d\t",path[k]);
				//printf("clomn");
			}
			printf("\n");
			return ;
		}
	
		path[p] = A[i][j];
		
	// move to right	
	printAllPaths(A, i, j+1, m, n, path,p+1);
	// move to down
	printAllPaths(A, i+1, j, m,n,path, p+1);
	
	// move diagonally
	
	// printAllPaths(A, i+1,j+1,m,n,path,p);
	
	}
int main()
	{
		int A[2][3] = { {1, 2, 3}, {4, 5, 6} };
		int path[16] ;
	printAllPaths(A,0,0,2,3,path,0);
	
	}