#include<stdio.h>
#define N 9

int findemptycell(int G[N][N], int *r, int *c)
{
	int i,j;
	for(*r=0;*r<N;(*r)++)
	{
		for(*c=0;*c<N;(*c)++)
		{
			if(G[*r][*c]==0)
				return 1;
			
			
		}
		
		
	}
	
	return 0;
	
	
}


int checkBox(int G[N][N], int r, int c, int num)
{
	int i, j;
	for(i=r;i<r+3;i++)
		for(j=c;j<c+3;j++)
			if(G[i][j]==num)
				return 0;
	return 1;		
	
	
	
}
int checkColumn(int G[N][N], int r, int c, int num)
{
	
	int i;
	
	for(i=0;i<N;i++)
	{
		if(G[i][c]==num)
			return 0;
		
		
	}
return 1;	
	
	
}

int checkRow(int G[N][N], int r, int c, int num)
{
	
	int i;
	
	for(i=0;i<N;i++)
	{
		if(G[r][i]==num)
			return 0;
		
		
	}
return 1;	
	
	
}


int isSafe(int G[N][N], int r, int c, int num)
{
	
	if(checkRow(G,r,c,num) && 
	 checkColumn(G, r, c, num) &&
	 checkBox(G, r-r%3, c-c%3, num ))
		return 1;
	return 0;	
	
	
}



int solve(int G[N][N])
{
int r,c,num;

if(!findemptycell(G, &r, &c))
	return 1;

	
	for(num=1; num<=N; num++)
	{
		if(isSafe(G,r,c,num))
		{
			G[r][c] = num;
			
			if(solve(G))
				return 1;
			G[r][c] = 0;
			
		}
		
		
	}
	


return 0;




}

void printgrid(int G[N][N])
{
	
	
	int i, j;
	for(i=0;i<N;i++){
		printf("[");
		for(j=0;j<N;j++)
		{printf("\t%d",G[i][j]);}
		printf("]\n");
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
					  
    if(solve(g))
			printgrid(g);
	else	
			printf("No solution exists");

return 0;		
	
	
}