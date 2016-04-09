#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int findmax(int *arr, int *start, int *finish, int n)
{
	
	int sum=0,maxsum=0;
	
	int i, local;
	*finish = -1;
	for(i=0;i<n;i++)
	{
		sum +=arr[i];
		if(sum<0)
		{
			sum =0;
			local = i+1;
		}
		
		if(sum>maxsum)
		{
			maxsum = sum;
			*start = local;
			*finish = i; 
		}
	}
	
	if((*finish)!=-1)
			return maxsum;
		
	maxsum = arr[0];
	*start = *finish = 0;
	for(i=1;i<n;i++)
	{
		if(arr[i]>maxsum)
		{
			maxsum= arr[i];
			*start = *finish = i;
		}
		
	}
	
	return maxsum;
	
}

void findMaxSum(int M[4][5], int R, int C)
{
	int left, right, sum=0, maxsum=0;
	int topl, topr, bottoml, bottomr, start, finish;
	int temp[R];
	int i;
	for(left=0; left<C; left++)
	{
		memset(temp, 0, sizeof(temp));
		for(right=left; right<C; right++)
		{
			
			for(i=0;i<R;i++)
			{
				temp[i] +=M[i][right];
				
			}
			
			sum = findmax(temp, &start, &finish, R);
			if(sum>maxsum)
			{
				maxsum = sum;
				topl = left;
				topr = right;
				bottoml = start;
				bottomr = finish;
			}
			
		}
		
	}
	
	printf("(%d,%d)\n",bottoml,topl);
	printf("(%d,%d)\n",bottomr,topr);
	printf("max sum:%d\n",maxsum);
	
}

int main()
	{
	int R=4;int C=5;
	int M[4][5] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
	
	findMaxSum(M, R, C);
	
	return 0;
	}