// Spiral Priting
#include<stdio.h>
#include<stdlib.h>
#define N 4
#define M 4
void printSpiral(int A[N][M])
	{
	
		int L=0, R=M-1;
		int T=0, B= N-1;
		int dir = 0;
		int i,j,k,l;
		while(L<=R && T<=B)
		{
			if(dir==0)
			{
			for(i=L;i<=R; i++)
				printf("%d, ",A[T][i]);
			
				
					T++;
				}
		else if(dir==1){		
		for(j=T; j<=B; j++)
				printf("%d, ",A[j][R]);
			R--;
				
			}
		else if(dir == 2)
		{			
		for(k=R; k>=L; k--)
				printf("%d, ",A[B][k]);
		B--;
			
			}
		else if(dir == 3)
		{
			//printf("==%d %d==",B, T);
		for(l=B; l>=T; l--)	
		{printf("%d, ",A[l][L]);
	//printf("==%d %d==",B, T);
	}
		L++;
			}
		
			dir = (dir+1)%4;
		
		}
	
	
	
	
	
	}

int main()
	{
	
		int A[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
		printSpiral(A);
		
	
	
	
	}