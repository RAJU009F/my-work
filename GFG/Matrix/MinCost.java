import java.io.Serializable;
import java.lang.*;
import java.util.*;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Matrix
# Problem Statement	: Min cost to reach from (0,0) to (M, N)
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class MinCost
{
	
	public static int min(int a,  int b)
	{
		
		return a>b?b:a;
	}
	public static int minCost(int arr[][],  int M, int N)
	{
		if(M<0 || N<0)
			return 0;
		else if(M==0 && N==0)
			return arr[M][N];
		else
			return arr[M][N]+min(minCost(arr, M-1, N), minCost(arr, M, N-1));
		
		
		
	}
	
	public static int minCostIterative(int arr[][], int M, int N)
	{
		// int[][] C=new int[M+1][N+1];
		
		// for(int i=1; i<=M; i++)
		// {
			// for(int j=1; j<=N; j++)
			// {
				// C[i][j] = arr[i][j];
				
				// if(i>0 && C[i][j] > C[i][j]+C[i-1][j])
					 // C[i][j] = C[i][j]+C[i-1][j];
				 // if(j>0 && C[i][j] > C[i][j] + C[i][j-1])
					  // C[i][j] =C[i][j]+C[i][j-1];
				//  if(i>0&&j>0&& C[i][j]>arr[i][j]+C[i-1][j-1])
					// C[i][j] = arr[i][j]+C[i-1][j-1];
				
				
				
			// }
			
			
			
		// }
		
		// return C[M][N];
		
		
		
		int[][] C =  new int[M][N];
		C[0][0] = arr[0][0];
		for(int i=1; i<M; i++)
				C[i][0] = arr[i][0] + C[i-1][0];
		for(int j=1; j<N; j++)
				C[0][j] = arr[0][j] + C[0][j-1];
			
		for(int i=1; i< M; i++)
		{
			for(int j=1; j<N; j++)
			{
				
				C[i][j] = arr[i][j] + min(C[i-1][j-1], min(C[i-1][j], C[i][j-1]));
			}
			
		}
		
		return C[M-1][N-1];
		
	}
	
	public static void main(String args[])
	{
		int M=3,N=3;
		int[][] arr = { 	{1, 2, 3},
							{4, 8, 2},
							{1, 5, 3} };
		System.out.println(minCost(arr,M-1,N-1));
		
		System.out.println(minCostIterative(arr,M,N));
		
		
		
	}
	
	
	
}