#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 // print the matrix in sorted order
 
void youngfy(int M[4][4], int n, int i,  int j)
{
	int d = i+1<n?M[i+1][j]:INT_MAX;
	int r = j+1<n?M[i][j+1]:INT_MAX;
	
	if(d==INT_MAX && r== INT_MAX)
			return;
	if(d<r)
	{
		M[i][j] = d;
		M[i+1][j] = INT_MAX;
		youngfy(M,n,i+1,j);
		
	}
	else{
		
		M[i][j] = r;
		M[i][j+1] = INT_MAX;
		youngfy(M,n,i,j+1);
		
	}
	
	
}

int extractMin(int M[4][4],int n)
{
	
	int result =  M[0][0];
	M[0][0] = INT_MAX;
	youngfy(M,n, 0,0);
	
	return result;
}

void printSorted(int M[4][4], int n)
{
	int i;
	for(i=0; i<n*n;i++)
	{
		printf("%d \t",extractMin(M, n) );
		
		
	}
	
	
}
int main()
	{
	int n=4;
	int M[4][4] ={{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},};
	printSorted(M, n);
	return 0;
	}
