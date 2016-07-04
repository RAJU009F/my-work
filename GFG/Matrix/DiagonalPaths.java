import java.io.Serializable;
import java.lang.*;
import java.util.*;


//import Employee;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Matrix
# Problem Statement	: print all paths diagonally
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class  DiagonalPaths
{

public static boolean isValid(int i, int j , int M, int N)
{
	return ((i>=0)&&(i<M)) && ((j>=0) &&(j<N));
	
	
}

public static void diagonolPrint(int arr[][], int M, int N)
{
		int i,j;
	for(int k = 0; k<M; k++)
	{
		i = k;
		j = 0;
		while(isValid(i,j, M,N))
			
		{
			System.out.print(arr[i][j]+" ");
			i--;
			j++;
		}
		System.out.println();
		
		
	}
	
	for(int k = 1; k<N; k++)
	{
		i = M-1;
		j = k;
		
		while(isValid(i,j, M, N))
		{
			System.out.print(arr[i][j]+" ");
			j++;
			i--;
			
		}
		System.out.println();
		
	}
	
	
}

public static void main(String args[])
{
	int[][] arr = {{1,2,3},{4,5,6},{9,10,11}};//,{

	diagonolPrint(arr,  3, 3);

}





}