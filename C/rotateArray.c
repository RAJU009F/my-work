#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[3][4], int m, int n)
{
		int i,j;
		for(i=0;i<m;i++)
		{for(j=0;j<n;j++)
			{
				printf("%d\t",*(arr+j*n+j));
				
				
		}}
	
	
	
}
void rotateArray(int image[3][4], int m,int n)
	{
		int *psource;
		int d[n][m];
		//printArray(image,m,n);
		
		int i, j;
		
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				d[j][m-i-1] = image[i][j];
					
				
			}
			
		}
	
		for(i=0;i<n;i++)
		{for(j=0;j<m;j++)
			{
				printf("%d\t",d[i][j]);
				
				
		}
		printf("\n");
		}
	
	
	}

int main()
	{
	
	int image[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
	int m=3, n=4;
	rotateArray(image,3,4);
	
	return 0;
	
	}