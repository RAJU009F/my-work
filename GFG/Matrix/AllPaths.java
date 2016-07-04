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

class AllPaths
{
	public static int totalPaths( int M, int N )
	{
		int[][] count =  new int[M][N];
		
		for(int i=0; i<M; i++)
			count[i][0] = 1;
		for(int j=0; j<N; j++)
			count[0][j] = 1;
		
		for(int i=1; i<M; i++)
		{
			for(int j=1; j<N; j++)
			{
				count[i][j] = count[i][j-1] + count[i-1][j];
				
				
			}
			
		}
		
		return count[M-1][N-1];
		
	}
	
	
	public static void main(String args[])
	{
		
		// int[][] arr = {}
int M=3, N=3;
		System.out.println(totalPaths( M, N));
	}
	
	
	
	
}