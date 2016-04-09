// finding the connected components:

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define R 5
#define C 5


int isSafe(int M[][C], int r, int c, int visited[][C])
{
	return ((r>=0) &&(r<R) &&
			(c>=0) && (r<C) &&
			M[r][c] && !visited[r][c]);
	
	
}
void DFS(int M[][C], int r, int c, int visited[][C])
{
	static int Rn[] = {-1,-1,-1,0,0,1,1,1};
	static int Cn[] = {-1,0,1,-1,1,-1,0,1};
	
	visited[r][c]=1;
	int k;
	for(k=0;k<8;++k)
	{
		if(isSafe(M,Rn[k]+r,Cn[k]+c,visited))
			DFS(M, Rn[k]+r, Cn[k]+c, visited);
		
		
	}
	
	
	
}


int  findconcoms(int M[][C])

{
	int count = 0;
	int visited[R][C];
	memset(visited,0,sizeof(visited));
	
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(M[i][j] && !visited[i][j])
			{
				DFS(M, i, j, visited);
				++count;
				
			}
			
			
		}
		
	//
		
		
	}
	
	
	return count;
	
	
}


int main()
	{
	
	
	int M[][C]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
    printf("Number of islands is: %d\n", findconcoms(M));
	
	return 0;
	
	}