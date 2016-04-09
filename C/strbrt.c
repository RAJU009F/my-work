#include<stdio.h>
#include<stdlib.h>

void compute_lps(char P[], int m, int lps[])
{
	int i=1, len=0;
	lps[0]=0;
	while(i<m)
	{
		if(P[i]==P[len])
		{
			len++;
			lps[len] = i;
			i++;
			
		}else if(len>0)
			len = lps[len-1];
		else
		{len =0;
	i++;}
		
		
		
	}
	
	
	
}

int KMP(char T[], int n, char P[], int m)
{
	int lps[m];
	compute_lps(P,m,lps);
	int i=0,j=0;
	while(i<n){
		if(P[j]==T[i])
		{
			
			i++;
				j++;
			if(j == m)
			{
				printf(" found at %d\n\n", i-j);
				j= lps[j-1];
				
			}
			
			
		}else if(j>0)
		{
			j = lps[j-1];
		}else
		{
			i++;
		}
		
		
		
	}	
	
	
}

void find_matching(char T[], char P[], int n ,int m )
	{
		int i, j;
		//printf("%s",T);
		for(i=0;i<n-m+1;i++)
			{
				j=0;
				//printf("%c", T[i]);
				while(j<m && P[j]==T[i+j])
					{
						j++;
						//printf("%c %c" ,P[j], T[i+j] );
					}
				if(j==m)
					{
						printf("match start index:{%d}\n",i);
					
					}
			}
			
	
	
	
	}
int main()
	{
	char T[] = "ABAABAAABAA";
	char P[] = "ABAA";
	int m = strlen(P);
	int n = strlen(T);
	printf("%d %d",n,m);
	find_matching(T, P, n ,m );
	
	KMP(T, n, P ,m);
	
	}