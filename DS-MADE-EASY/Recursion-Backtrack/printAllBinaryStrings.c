#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author:: @RAJ009F
# Problem Statement: print all possible binary strings of size n.
# Description:
#Complexity: O(2^n)
sample output:
3

000
100
010
110
001
101
011
111
*/

void printAllBinaryStrings(char A[100], int n)
{
	if(n<1)
	{
		printf("%s\n",A);
		return ;
		
		
	}
	
	A[n-1] = '0';
	printAllBinaryStrings(A,n-1);
	A[n-1] = '1';
	printAllBinaryStrings(A, n-1);
	
	
	
}
int main()
	{
	
	int n;
	
	scanf("%d",&n);
	char A[n];
	printf("\n");
	printAllBinaryStrings(A,n);
	
	return 0;
	}	