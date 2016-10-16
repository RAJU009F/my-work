import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Backtracking
# Problem Statement	: Knight Tour: find the path of Knight to verify ll it crossing all the cells in chess board or not 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class KnightTour
{
	private static int N = 8;
	
	
	public static  void knightTour()
	{
		int[][] sol =  new int[N][N];
		
		int[] moveX   = {  2, 1, -1, -2, -2, -1,  1,  2 };
		int[] moveY	= {  1, 2,  2,  1, -1, -2, -2, -1 };
		int move = 1;
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				sol[i][j] = -1;	
			}		
		}
		
		sol[7][7] = 0;
		
		if(knightTourUtil(0, 0, move, moveX, moveY, sol ))
		{
			System.out.println("Knight Tour:");
			printPath(sol);
			
		}else
			System.out.println("Knight Tour not possible");
			
	}
	
	public static boolean knightTourUtil(int x, int y,  int move,  int moveX[], int moveY[], int sol[][])
	{
		//System.out.println(move);
		int movex;
		int movey;
		if(move == N*N)
		{
			return true;
			
		}
		
		for(int k=0; k<N; k++)
		{
			 movex = x + moveX[k];
			movey = y + moveY[k];
			
			if(isSafeMove(sol, movex, movey))
			{
				sol[movex][movey] = move;
				if(knightTourUtil(movex, movey, move+1, moveX, moveY, sol))
						return true;
				else	
					sol[movex][movey] = -1;	
			}
			
		}
		
		return false;
		
	}
	
	public static boolean isSafeMove(int sol[][],  int x, int y)
	{
		return ((x>=0) && (x<N) && (y>=0) && (y<N) && sol[x][y]==-1);
		
	}
	
	public static void printPath(int sol[][])
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
				System.out.print(sol[i][j]+" ");
		System.out.println(" ");	
		}
		
	}
	
	
	
	public static void main(String args[])
	{
		
		knightTour();
		
		
		
	}
	
	
}
