import java.io.*;
import java.lang.*;
import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/String
# Problem Statement	: Longest Common SubString 
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class LCS
{
	public static void printLCS(char A[], char B[])
	{
		int m = A.length;
		int n = B.length;
		int[][] L=new int[m+1][n+1];
		int i;
		int j;
		for(i=0; i<=m; i++)
		{
			for(j=0; j<=n; j++)
			{
				if(i==0||j==0)
					L[i][j]=0;
				else if(A[i-1]==B[j-1])
					L[i][j] = L[i-1][j-1]+1;
				else
					L[i][j] = Math.max(Math.max(L[i-1][j], L[i][j-1]),L[i-1][j-1]);
				
				
			}
			
			
		}
		System.out.println(L[m][n]);
		i = m;
		j = n;
		while(i>0&&j>0)
		{
			if(A[i-1]==B[j-1])
			{
				System.out.print(A[i-1]);
				i--;
				j--;
			}
			else if(L[i-1][j]>L[i][j-1])
				{
					i--;
			
				}else
					j--;
		}	
		
		
		
	
	}

	public static void main(String args[])
	{
		String A = "AEDFHR";
		String B = "ABCDGH";
		 
	printLCS(A.toCharArray(), B.toCharArray());

	}

}