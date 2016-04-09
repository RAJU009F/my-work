#include<stdio.h>
#include<stdlib.h>
// magic square for ODD input ex 3,5,7 etc

void generateMagicSquare(int M[10][10], int n)
{
	int i=n/2;
	int j=n-1;
	
	int num;
	for(num=1;num<=n*n;)
	{
		if(i==-1 && j==n)
		{
			j= n-2;
			i=0;
			
		}else
		{
			if(i<0)
				i=n-1;
			if(j==n)
				j=0;
			
		}
		if(M[i][j])
		{
			j= j-2;
			i++;
			continue;
		
		}else
			M[i][j] = num++;
		i--;
		j++;
	
	
		
		
		
		
	}
	
	
	
}
void printMatrix(int M[10][10], int n)
{
	
	int i, j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",M[i][j]);
			
		}
		printf("\n");
		
	}
	
}
int main()
	{
	int n=7;
	int M[10][10];
	memset(M,0,sizeof(M));

	generateMagicSquare(M, n);
	
	printMatrix(M,n);
	
	
	}