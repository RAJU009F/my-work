#include<stdio.h>
#include<stdlib.h>
// fill the array with new colour 
void floodFillUtil(int M[8][8], int n, int x, int y,  int prevCol ,int newCol)
{
		if(x<0 || x>=n || y<0 || y>=n)
				return ;
		if(M[x][y] != prevCol)
				return;
			
		M[x][y] = newCol;	
		floodFillUtil(M, n, x+1, y, prevCol, newCol);	
		floodFillUtil(M, n, x, y+1, prevCol, newCol);	
		floodFillUtil(M, n, x-1, y, prevCol, newCol);	
		floodFillUtil(M, n, x, y-1, prevCol, newCol);			
	
	
}
void floodFill(int M[8][8], int x, int y, int n, int newCol)
{
		int prevCol = M[x][y];
		
		floodFillUtil(M, n, x,y,prevCol, newCol);
	
	
}
int main()
	{
		
		int x=4, y=4, newCol=3;
		int n=8;
		int M[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
		
	
	floodFill(M,x,y,  n,newCol);
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d\t", M[i][j]);
			
		}
		printf("\n");
		
		
	}
	
	}
