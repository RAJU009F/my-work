#include<stdio.h>
#include<stdlib.h>

// Modify Boolean Matrix : set all 1s in a row and column in a matrix if a cell having 1.

void printMatrix(int M[3][4],int  m,int  n)
{
		int i,j;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{				
				printf("%d\t",M[i][j]);
				
			}
				printf("\n");
			
		}
	
	
	
	
}

void modifyMatrix(int M[3][4], int m ,int n)
{
	
	int row_flag = 0;
	int col_flag = 0;
	int r,c;
	
	// step 1: check if 1s present in 1st row and 1st column
	for(r=0;r<m;r++)
			if(M[r][0]==1)
				row_flag=1;
	for(c=0;c<n;c++)
			if(M[0][c]==1)
					col_flag=1;
	// step 2: check for 1s in remaining cells and update/set the first cell of respective row and columns 
	for(r=0;r<m;r++)
	{
		for(c=0;c<n;c++)
		{
			if(M[r][c])
			{
				M[r][0] =1;
				M[0][c]=1;
			}		
		}
	}
	
	// step 3: update the respective columns or rows as per the values in the first row and first column.
	
	//a. update rows:
		for(r=1; r<m; r++)
				if(M[r][0])
				{
					for(c=0; c<n; c++)
					{
						M[r][c] = 1;
					}
					
				}
	
	// b. update columns
		for(c=1;c<n;c++)
				if(M[0][c])
				{
					for(r=0; r<m; r++)
					{
						M[r][c] = 1;
					}
					
				}
				
		// step 4: update the 1st row and 1st column 		
			if(row_flag)
			{for(c=0;c<n;c++)
					M[0][c] = 1;}
			if(col_flag)
			{
				for(r=0;r<m;r++)
				{		M[r][0] = 1;}
				
			}
}
int main()
	{
		int m=3, n=4;
		int M[3][4]={ {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
    };
		printMatrix(M,m,n);
		modifyMatrix(M,m,n);
		printf("\n\n\n");
		printMatrix(M,m,n);
	
	
	}