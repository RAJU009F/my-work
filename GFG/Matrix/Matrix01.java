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

class Matrix01
{

	public static void makeMatix01(int arr[][], int M, int N)
	{
		boolean rFlag = false;
		boolean cFlag = false;
		// traverse 1st row to set cFlag
		for(int j=0; j<N;j++)
				if(arr[0][j]>0)
					cFlag = true;
		// traverse 1st	columns to set rFlag

		for(int i=0; i<M; i++)
			if(arr[i][0]>0)
				rFlag = true;
		for(int i=0; i<M; i++)
		{
			
			for(int j=0; j<N; j++)
			{
				if(arr[i][j]>0)
				{
					arr[i][0] = 1;
					arr[0][j] = 1;
					
					
				}
					
				
				
				
			}
			
			
		}


			for(int i=1; i<M; i++)
			{
				for(int j=1; j<N; j++)
				{
					if(arr[i][0]>0 || arr[0][j]>0)
						arr[i][j] = 1;
					
					
				}
				
			}
			
		if(cFlag)
			for(int j=0; j< N; j++)
				arr[0][j] = 1;
		if(rFlag)
			for(int i=0; i<M; i++)
				arr[i][0] = 1;
		
		
	}
	
	public static void printMatrix(int arr[][], int M, int N)
	{
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<N; j++)
			{
				
				System.out.print(arr[i][j]+" ");
				
				
			}
			System.out.println("");
			
			
		}
		
		
	}
	public static void main(String args[])
		{
			int M=3;
			int N = 4;
			int[][] arr= {{1, 0, 0, 1 }, {0, 0, 1, 0}, {0, 0 ,0 ,0}};
			
			System.out.println("Input:");
			printMatrix(arr,M, N);
		
			makeMatix01(arr, M, N);
		
			System.out.println("Output:");
			printMatrix(arr,M, N);
		
		}




}