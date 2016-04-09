#include<stdlib.h>
#include<stdio.h>

// min cost path in mTRIX
int min(int x,int y, int z)
{
	if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
	
	
}
int minCost(int M[3][3],int m,int n)
{
		if(n<0 || m<0)
			return 0;
		else if(m==0 &&n==0)
				return M[m][n];
		else
				return M[m][n]+min( minCost(M, m,n-1), minCost(M, m-1, n-1), minCost(M,m-1,n));
	
}
int minCost_r(int M[3][3], int m, int n)
{
	int t[3][3];
	
	int r,c;
	t[0][0] = M[0][0];
	for(r=1;r<=m;r++)
		t[r][0] = t[r-1][0] + M[r][0];
	for(c=1;c<=n;c++)
		t[0][c] = t[0][c-1] + M[0][c];

	for(r=1;r<=m;r++)
	{
		for(c=1;c<=n;c++)
		{
			t[r][c] = min(t[r-1][c], t[r][c-1], t[r-1][c-1]) + M[r][c];
			
		}
		
		
	}
		
	return t[m][n];
	
	
	
}


int main()
	{
	
	int M[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
	printf("%d\n",minCost(M,2,2));	
	printf("%d\n",minCost_r(M,2,2));	
	return 0;
	
	}
	