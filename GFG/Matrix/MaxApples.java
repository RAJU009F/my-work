import java.io.Serializable;
import java.lang.*;
import java.util.*;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Matrix
# Problem Statement	: Maximum Apples from top-left to bottom-right
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class MaxApples
{
	public static int maxApples(int arr[][] ,int M, int N)
	{
		int[][] max = new int[M][N];
		
		max[0][0] = arr[0][0];
		
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<N; j++)
			{
				max[i][j] = arr[i][j];
				if(i>0 && max[i][j]< arr[i][j]+max[i-1][j])
					max[i][j] = arr[i][j]+max[i-1][j];
				if(j>0 && max[i][j]< arr[i][j]+max[i][j-1])
					max[i][j] = arr[i][j]+max[i][j-1];
				
				//if(i>0&&j>0 && max[i][j]< arr[i][j]+max[i-1][j-1])
					//max[i][j] = arr[i][j]+max[i-1][j-1];
				
				
				
				
			}
			
			//System.out.println(i+" ");
		}
		
		return max[M-1][N-1];
		
		
		
	}
	
	public static void main(String args[])
	{
		int M=3;
		int N =4;
		
		int[][] arr = {{1,2,3,4 }, {1,1,1,1},{9,9,9,9}};
		
		System.out.println(maxApples(arr, M,N));
		
		
	}
	
	
	
	
}