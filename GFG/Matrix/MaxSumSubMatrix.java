import java.io.Serializable;
import java.lang.*;
import java.util.*;


//import Employee;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Matrix
# Problem Statement	: Maximum sum sub matrix
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class MaxSumSubMatrix
{
	
	
	public static void findMaxSumSub(int arr[][],  int M, int N)
	{
		
			int maxSum=-1000000, finalLeft=-1, finalRight=1, finalTop=1, finalBottom=-1;
			
			
			
			for(int i=0; i<N; i++)
			{
				int[] temp =  new int[M];
				for(int k=0; k<M; k++)
					temp[k] = 0;
				
				for(int j=0; j<N; j++)
				{
					for(int k=0; k<M; k++)
					temp[k] += arr[k][j];
				
					int start=0; int stop=-1; int   localSum=0;
					int curSum=0;
					for(int k=0; k<M; k++)
					{
						localSum +=temp[k];
						if(localSum < 0)
						{
							localSum = 0;
							start = k+1;
						}
						if(localSum > curSum)
						{
							curSum = localSum;
							stop = k;
					
					
						}
						
					}
					
					if(stop == -1)
					{	curSum = -1000000;
					for(int k=0; k<M; k++)
					{
						if(curSum <temp[k] )
						{
							curSum = temp[k];
							start = stop = k;
						}
					}}
					
				if(maxSum < curSum)
				{
					maxSum = curSum;
					finalBottom = stop;
					finalLeft = i;
					finalRight = j;
					finalTop = start;
				}
					
					
				}
				
				
			}
		
		System.out.println( "MaxSum:"+maxSum+"finalBottom: "+finalBottom+"finalLeft: "+finalLeft+"finalRight: "+finalRight+"finalTop: "+finalTop);
		
	}
	
	public static void main(String args[])
	{
		int[][] arr = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
					  
		findMaxSumSub(arr, 4, 5);			  
		
		
		
		
	}
	
	
	
	
}


