#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int x,int y)
	{
		return x>y?x:y;
	
	}

int lcs1(char *x,int i,int m,char *y,int j,int n)
	{
		if(j==n||i==m)
			return 0;
		else if(x[i]==y[j])
			return 1+lcs1(x,i+1,m,y,j+1,n);
		else
			return max(lcs1(x,i+1,m,y,j,n),lcs1(x,i,m,y,j+1,n));		
	
	
	
	}
	
int L[1024][1024];	
int lcs(char *x,int m,char *y,int n)	

	{
	
		int i,j;
		for(i=0;i<=m;i++)
			L[i][n]=0;
		for(j=0;j<=n;j++)
			L[m][j]=0;	
		for(i=m-1;i>=0;i--)
			{
				for(j=n-1;j>=0;j--)
					{
						L[i][j]=L[i+1][j+1];
						
						if(x[i]==y[j])
							L[i][j]++;
						if(L[i+1][j]>L[i][j])	
							L[i][j]=L[i+1][j];
						if(L[i][j+1]>L[i][j])	
							L[i][j]=L[i][j+1];
							
							
					
					
					
					
					}
			
			
			
			
			
			}
		return L[0][0];
	
	}
main()
	{
		char x[]="NAXALITEISTHEMANINDIANHI";
		char y[]="INDIANHITLERNAXTHE";
		
		int m=strlen(x);
		int n=strlen(y);
			printf("\nLCS :: %d\n\n",lcs(x,m-1,y,n-1));
		printf("\nLCS::%d\n\n",lcs1(x,0,m-1,y,0,n-1));
	
	
	}
