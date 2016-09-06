// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/ARRAY
# Problem Statement	: Sub Array with given sum
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void swap(int *a, int *b)
{
	int t =*a;
	*a  = *b;
	*b =t;
	
	
}

void heapiFy(int arr[],  int i, int size)
{
	int max  = i;
	int l =  2*i+1;
	int r =  2*i+2;
	
	if(l<size && arr[max]<arr[l])
		max = l;
	if(r<size && arr[max]<arr[r])
		max =  r;
	
	if(i!=max)
	{
		swap(&arr[max], &arr[i]);
		heapiFy(arr, max, size);
		
	}
	
	
	
}
void sort(int arr[], int n)
{
	int i;
	for(i=n/2-1; i>=0; i--)
	{
		heapiFy(arr, i, n);
	}
	
	for(i=n-1; i>=0; i--)
	{	swap(&arr[0], &arr[i]);
		heapiFy(arr, 0, i);}
	
	
	
}
void findnums(int arr[], int n , int x)
{
	sort(arr, n);
	int i,j,l,r;
	for(i=0; i<n-3; i++)
	{
		for(j=0; j<n-2; j++)
		{
			l= j+1;
			r = n-1;
			
			while(l<r)
			{
				if(arr[i]+arr[j]+arr[l]+arr[r] == x)
				{
					printf("%d+%d+%d+%d = %d\n",arr[i], arr[j], arr[l], arr[r], x );
					r--;
					l++;
					
					}
					
				else if(arr[i]+arr[j]+arr[l]+arr[r] > x)
						r--;
				else
						l++;
			}
			
			
			
		}
		
	}
	
	
	
}


int main()
{
	
	int arr[] = {1, 4, 45, 6, 10, 12};
	
	findnums(arr, sizeof(arr)/sizeof(arr[0]), 21);
	
	
	
}
