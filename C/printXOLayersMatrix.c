#include<stdio.h>
#include<stdlib.h>
#define RR 6
#define CC 6

void buildXOLayers(char M[16][16], int m, int n)
{
	int L,B, T, R;
	int i,j;
	char x = 'X';
	L=B=0;
	T=n-1;
	R=m-1;
	while(L<=T || B<=R)
	{
		
		for(i=L; i<=T; i++)
		{
			
			M[B][i] = x;
		}
		B++;
		for(i=B; i<=R; i++)
		{
			M[i][T] = x;
			
		}
		T--;
		
		for(i=T; i>=L;i--)
				M[R][i] = x;
			
		R--;	
		
		for(i=R; i>=B; i--)
				M[i][L] = x;
		L++;
		x = x=='O'?'X':'O';		
		
	}
	printf("printing array\n");
	for(i=0;i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		  printf("%c\t", M[i][j]); 
			
		}
			printf("\n");
	}
	
	
}
int main()
	{
	
	 char M[16][16];
	 
	 buildXOLayers(M, 6, 6);
	 
	 buildXOLayers(M, 6, 5);
	  buildXOLayers(M, 5, 6);
	   buildXOLayers(M, 4, 4);
	    buildXOLayers(M, 3, 4);
	
	}