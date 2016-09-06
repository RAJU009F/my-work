// import java.io.*;
// import java.lang.*;
// import java.util.*;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Array
# Problem Statement	: Non Repeating Numbers
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
void findNonRepeatnums(int arr[],  int size)
{
	//int *x =  (int *) malloc(sizeof(int));
	// in t *y = (int *) malloc(sizeof(int));
	int x = 0;
	int y = 0;
	int xor = arr[0];
	int set_bit;
	int i;
	for(i=1; i<size; i++)
	{
		xor ^=arr[i];
		
		
		
	}
	
	set_bit = xor & ~(xor-1);
	
	for(i=0; i<size; i++)
	{
		if(arr[i]&set_bit)
			x = (x)^arr[i];
		else
			y = (y)^arr[i];
		
	}
	
	printf("%d, %d", x, y);
	
	
}



int main()
{
	
	int arr[] = {2,3,11,12,9,7,2,3,12,11};
	
	int size  =  sizeof(arr)/sizeof(arr[0]);
	
	findNonRepeatnums(arr, size);
	
	
}
