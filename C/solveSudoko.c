
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 9

bool isSolved(int g[N][N], int *r,  int *c)
{
		
		for(*r=0;*r<N;(*r)++)
			for(*c=0;*c<N;(*c)++)
			{
				if(!g[*r][*c])
					return false;
				
			}
	
	return true;
	
}

bool checkcol(int g[N][N], int col, int num)
{
	int i;
		for(i=0; i<N; i++){
			if(g[i][col] == num)
				return true;
		}
		
		return false;
	
}

bool checkrow(int g[N][N], int row, int num)
{
	int j;
	for(j=0;j<N;j++)
	{
		if(g[row][j]==num)
			return true;
	}
	
	return false;
	
}

bool check3by3grid(int g[N][N],int r, int c, int num)
{
	int i;
	int j;
	for(i=0;i<3; i++)
	{
		for(j=0;j<3;j++)
		{
			if(g[i+r][j+c]==num)
					return true;
			
			
		}
		
	}
			return false;
	
	
}

bool isSafe(int g[N][N], int row, int col, int num)
{

	return ( !checkcol(g, col, num) &&
			!checkrow(g, row, num) &&
			!check3by3grid(g,row-row%3, col-col%3, num));

}



bool validSudoko(int g[N][N])
	{
		int row,col;
		int i;
		if(isSolved(g, &row, &col))
			return true;
			
		for(i=1;i<=N;i++)
			{
				if(isSafe(g,row, col, i))
				{
					g[row][col] = i;
					if(validSudoko(g))
						return true;
						
						g[row][col]=0;
					
					
					
				}
			
			
			
			
			}
			return false;
	
	
	
	}
	
void printGrid(int g[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%2d ",g[i][j]);
			
			
		}
		printf("\n");
		
	}
	
	
	
	
}
	
	
int main()
{
	
	int g[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	
	if(validSudoko(g))
		printGrid(g);
		//printf("Valid Sudoko\n\n");
	else
		printf("Not a valid sudoko\n\n");
	
	
	
}	