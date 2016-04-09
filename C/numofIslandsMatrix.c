#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

#define R 5
#define C 5
// count the num of islands in 
int isSafe(int r, int c, int RR, int CC, int M[R][C], int visited[R][C])
{
		
	return (r<R && r>=0 && c>=0 && c<C && M[r][c] &&!visited[r][c]);
	
}
void NoofIslandsUtil(int M[R][C], int r, int c, int visited[R][C])
{
		int RM[8] ={-1, -1, -1,0, 0,1,1,1};
		int CM[8] = {-1, 0, 1, -1, 1,-1,0,1};
		visited[r][c] = 1;
		int k;
		for(k=0; k<8; k++)
		{
			if(isSafe(r+RM[k], c+CM[k], R, C, M, visited))
				NoofIslandsUtil(M, r+RM[k], c+CM[k], visited);
		}
		
}

int NoofIslands(int M[R][C], int RR, int CC)
	{
		int visited[R][C];
		int i, j;
		int count=0; 
		memset(visited, 0, sizeof(visited));
		
		for(i=0; i<R; i++)
		{
			for(j=0; j<C; j++)
			{
				if(M[i][j] && !visited[i][j])
				{
					NoofIslandsUtil(M, i, j, visited);
					++count;
					
				}
				
				
			}
			
		}
	return count;
	
	}

int main()
	{
		int M[R][C] = {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
		printf("%d \n", NoofIslands(M,R,C));
	
	}