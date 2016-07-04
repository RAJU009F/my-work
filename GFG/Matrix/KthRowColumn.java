import java.io.Serializable;
import java.lang.*;
import java.util.*;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Matrix
# Problem Statement	: find k such that all elements in k’th row are 0 and k’th column are 1.
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class KthRowColumn
{

public static int findK(int arr[][], int n)
{
	int i=0;
	int 	j=n-1;
	int res= -1;
	
	while(i<n || j>=0)
	{
		if(arr[i][j]==0)
		{
			while(j>=0 && (arr[i][j]==0 || i==j))
				j--;
			if(j==-1)
			{
				{res = i;
			break;}
			}else
				i++;
			
			
			
			
		}else
		{
			while(i<n && (arr[i][j] == 1 || i==j))
			i++;
			if(i==n)
			{res = j;
			break;
		}
			else
				j--;
		}
				
	}
	
	
	if(res == -1)
		return -1;
	for(i=0; i<n; i++)
		if(res !=i && arr[i][res] !=1)
			return -1;
	for( j=0; j<n; j++)
		if(res !=j && arr[res][j] !=0)
			return -1;
	return res;	
	
	
	
	
	
}


	public static void main(String args[])
	{
		int n =5;
		
		int[][] arr = {{0, 1, 0, 0, 0},
                      {1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1},
                      {0, 1, 0, 0, 0},
                      {0, 1, 0, 0, 1}};
					  
					  // {{0, 0, 1, 1, 0},
                      // {0, 0, 0, 1, 0},
                      // {1, 1, 1, 1, 0},
                      // {0, 0, 0, 0, 0},
                      // {1, 1, 1, 1, 1}};
		
		System.out.println(findK(arr, n));
		
		
		
	}



}