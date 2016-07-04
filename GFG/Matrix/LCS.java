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


class LCS
{
	public  static  int max(int a, int b)
	{
		
		return a>b?a:b;
	}
	
	public static int findLCS(String str1, String str2)
	{
		
		int m = str1.length();
		int n =  str2.length();
		
		int[][] L =  new int [m+1][n+1];
		
		for(int i=0; i<=m ; i++)
		{
				for(int j=0; j<=n; j++){
					if(i==0||j==0)
						L[i][j] = 0;
					else
					{
					if(str1.charAt(i-1) == str2.charAt(j-1))
						L[i][j] = L[i-1][j-1] +1;
					else
						L[i][j] = max(L[i-1][j-1], max(L[i-1][j], L[i][j-1]));
					}
				}
			
		}
		
		return L[m][n];
		
	}
	
	public static void main(String args[])
	{
		String  str1 = "ABCDGH";
		
		String str2 = "AEDFHR";
		
		System.out.println(findLCS(str1, str2));
		
		
		
		
	}
	
	
	
	
}
