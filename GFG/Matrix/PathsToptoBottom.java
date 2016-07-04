import java.io.Serializable;
import java.lang.*;
import java.util.*;


//import Employee;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG
# Problem Statement	: print all paths from top to bottom moving right or down
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class PathsToptoBottom{

public static void printPathsUtil(int arr[][], int i, int j,  int M, int N, int Path[], int k){

if(i>=M || j>=N)
		return;
	
	Path[k++] = arr[i][j];
	
	if(i==M-1 && j==N-1)
	{
		for(int l = 0 ; l<k; l++)
			System.out.print(Path[l]+" ");
		System.out.println();
		
		
		return ;
	}
	printPathsUtil(arr, i+1, j, M, N, Path, k);
	printPathsUtil(arr, i, j+1, M, N, Path, k);
	
}


public static void printPaths(int arr[][], int i, int j, int M,  int N)
{
	int[] Path = new int[M+N];
	printPathsUtil(arr, i, j, M, N, Path, 0);
	
}

public static void main(String args[])
{
	int M = 2;
	int N = 3;
	
	// int[][] arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
	int[][] arr = {{1,2,3},{4,5,6}};//,7},{9,10,11}};//,{13,14,15,16},{17,18,19,20}};
	printPaths(arr,0,0,M,N);
	
	
	
	
}


}