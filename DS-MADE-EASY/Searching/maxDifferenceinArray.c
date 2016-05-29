#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DSME/Searching
# Problem Statement	: find the trailing zeors in factorial of a num
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/

int maxDiff(int arr[], int n)
{
	int min[n];
	int max[n];
	
	int i,j;
	min[0]=arr[0];
	for(i=1; i<n; i++)
		min[i]= arr[i]>min[i-1]?min[i-1]:arr[i];
	
	max[n-1] = arr[n-1];
	for(j=n-2; j>=0; j--)
		max[j] = arr[j]>max[j+1]?arr[j]:max[j+1];
	
	i=j=0;
	int diff = -1;
	while(j<n&&i<n)
	{
		
		if(min[i]<max[j])
		{
			diff = diff>(j-i)?diff:(j-i);
			j++;
		}else
			i++;
		
	}
	
	// for(i=0; i< n; i++)
		// printf("%d\t",min[i]);
	
	
	// for(j=0; j< n; j++)
		// printf("%d\t",max[j]);
	return diff;
	
	
}

int main()

{

	int arr[] = {34,8,10,3,2,80,30,33,1};
	
	printf("max diff: %d\n",maxDiff(arr,sizeof(arr)/sizeof(arr[0])));

return 0;
}