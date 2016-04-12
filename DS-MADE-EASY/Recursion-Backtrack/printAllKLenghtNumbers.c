#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Problem Statement	: print all numbers of n leght from 0 to k-1
# Description		:
# Complexity			: O(k^n)

sample output		:
3
2
AAA
BAA
ABA
BBA
AAB
BAB
ABB
BBB

*/

void printAll0KNumbers(char A[], int n, int k)
{
	if(n<1)
	{
		printf("%s\n",A);
		return;
		
	}
	
	else
	{
		int i;
		for(i=0;i<k;i++)
		{
			A[n-1] = 65+i;	
			printAll0KNumbers(A,n-1,k);
		}
		
		
	}
	
	
	
	
}

int main()
	{
	
	int n, k;
	scanf("%d  %d", &n, &k);
	char A[n];
	printAll0KNumbers(A,n ,k);
	
	return 0;
	}