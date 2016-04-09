#include<stdio.h>
#include<stdlib.h>
#define R 6
#define C 5
// largest square sub martix

int min(int a, int b,int c)
	{
	
		int m=a;
		if(m>b)
			m=b;
		 if(m>c)
			m=c;
		return m;		
		
}

void printMaxSubMatrix(int M[R][C])
	{
		int S[R][C];

		int i,j;
		
		for(i=0;i<R;i++)
			S[i][0] = M[i][0];
		for(j=0;j<C;j++)
			S[0][j] = M[0][j];
			
	for(i=1; i<R; i++)
		{
		for(j=1;j<C;j++)
			{
			
			if(M[i][j] == 1)
				S[i][j] = min(S[i-1][j], S[i][j-1],S[i-1][j-1]) +1;
			else
				S[i][j]	= 0;
			
			}
		
		}
		
		int max_i=0, max_j=0, max_size=M[0][0];
		
		for(i=0;i<R;i++)
			{
			for(j=0;j<C;j++)
				{
					if(S[i][j]>max_size)
						{
						max_size = S[i][j];
						max_i = i;
						max_j = j;}
				
				}
			}
			
		//print matrix 	
			printf("%d \t%d\t %d\t\n",max_size,max_i, max_j);
		for(i= max_i;i>max_i-max_size;i--)
			{
				for(j=max_j;j>max_j-max_size;j--)
					{
						printf("%d\t",M[i][j]);
						
					
					}
				printf("\n");	
			
			}
	
	
	
	}

int main()
	{
		int M[R][C] = {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
		printMaxSubMatrix(M);
	
	
	}