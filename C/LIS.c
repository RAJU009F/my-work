#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void LIS(int *, int);
int ceilindex(int A[], int l, int r, int key);
void printLIS(int T[], int n);
int main()
	{
	
	int A[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
	int size = sizeof(A)/sizeof(A[0]);
	LIS( A,  size);
	return 0;
	}
void printLIS(int T[], int n)
		{
			int i;
			for(i=0;i<n;i++)
			{
				printf("\t[%d]",T[i]);
			
			}
		
		
		}
int ceilindex(int A[], int l, int r, int key)
			{
				int m;
				
				while(r-l>1)
					{
						m= l + (r-l)/2;
						if(A[m]>=key)
						{
							r=m;
						}else{
						
						l=m;
						}
					
					}
			return r;
			
			
			
			}
void LIS(int A[], int n)
{
	int T[n];
	int len,i, c;
	memset(T,0,n*sizeof(int));
	T[0] = A[0];
	len = 1;
	for(i=1;i<n;i++)
		{
			if(A[i]<T[0])
				T[0] = A[i];
			else if(A[i]>T[len-1])
				{T[len] = A[i];
				len++;}
			else
				{
				c= ceilindex(T,-1, len-1,A[i]);
				T[c]=A[i];
				printf("ll\t");
				}
		
		}
	
	

printf("len of LIS:%d\n\n",len);
printLIS(T, len);

}	