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
# Problem Statement	: Rat maze: find the Path from (0,0) to (N,N)
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class RatMaze{
	
	private static int N = 4;
	
	public static boolean isSafeMove(int maze[][], int x, int y){
		
		return (x<N && y<N &&maze[x][y]==1);
			
		
	}
	
	public static void printPath(int sol[][])
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(sol[i][j]==1)
					System.out.print("["+i+","+j +"]"+" ");
				
			}
			//System.out.println();	
		}
		
	}
	
	public static boolean ratMazePathUtil(int maze[][],  int x, int y,  int NN, int sol[][])
	{
	
		if(NN-1==x&&NN-1==y)
		{
			sol[x][y] =1;
			return true;
		}
		
		if(isSafeMove(maze,x,y))
		{
			sol[x][y]=1;
			
			if(ratMazePathUtil(maze, x+1, y, NN, sol))
				return true;
			
			if(ratMazePathUtil(maze, x, y+1, NN,  sol))
				return true;
			sol[x][y] = 0;
			return false;
			
			
			
		}
		
		return false;
		
		
	}

	public static void ratMazePath(int maze[][])
	{
		int sol[][] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
		};
		
		if(ratMazePathUtil(maze, 0, 0, N,  sol))
		{
			System.out.println("Path is ");
			printPath(sol);
			
		}else
		{System.out.println("Path not possible");}
		
		
		
	}
	
	public static void main(String args[])
	{
		
		
		int maze[][] = { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
		
		ratMazePath(maze);
		
		
	}
	
}