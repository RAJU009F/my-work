#include<stdio.h>
#include<stdlib.h>
// find the row with max 1s

void maxRow(int M[4][4], int n)
{
	int c=n-1,r;
	int max_row_index=-1;
	for(r=0;r<n;r++)
	{
		while(c>=0 && M[r][c])
		{
			c--;
			max_row_index =r;
			
		}
		
		
		
	}
	
	printf("max 1s row index : %d\n",max_row_index);
	
}
int main()
	{
		int n=4;
		int M[4][4] ={ {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
		maxRow(M,n);
	
	}