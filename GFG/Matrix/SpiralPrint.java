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

class SpiralPrint
{
	
	public static void spiralPrint(int arr[][], int M, int N)
	{
		int t=0, b= M-1, l=0, r=N-1;
			int i;
			while(t<b || l<r)
			{
				
				for(i=l; i<=r; i++)
				{
					System.out.print(arr[t][i]+" ");
					
					
				}
				t++;
				
				for(i=t; i<=b; i++)
				{
					
					System.out.print(arr[i][r]+" ");
				}
			r--;
				for(i=r; i>=l; i--)
				{
					System.out.print(arr[b][i]+" ");
					
				}
				
				b--;
				
				for(i=b; i>=t; i--)
				{
					
					System.out.print(arr[i][l]+" ");
				}
				l++;
				
				
				
				
			}
		
		
		
		
	}
	
	public static void main(String args[])
	{
		int M=4,N=6;
		int[][] arr = {{1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18},
		{23, 24, 25, 26, 227, 28}};
		
		spiralPrint(arr, M, N);
		
		
		
	}
	
	
	
}