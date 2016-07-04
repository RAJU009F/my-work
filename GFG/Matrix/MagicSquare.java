import java.io.Serializable;
import java.lang.*;
import java.util.*;


//import Employee;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Matrix
# Problem Statement	: Maximum sum sub matrix
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/
class MagicSquare
{
	
	public static void main(String args[])
	{
		
		Scanner sc =  new Scanner(System.in);
		int N = sc.nextInt();
		int[][] M = new int[N][N];
		for(int i =0; i<N; i++)
		for(int j=0; j<N; j++)	
			M[i][j] = 0;
		
		
		int i=N/2, j=N-1;
		for(int n=1; n<=N*N;)
		{
				if(i==-1 && j==N)
				{
					j=N-2;
					i = 0;
					
				}else
				{
					if(j==N)
						j=0;
					if(i<0)
						i = N-1;
					
					
					
				}
				
			if( M[i][j] >0 )
			{
				j = j-2;
				i++;
				continue;
			}else
				M[i][j] = n++;
				
			
		j++;
		i--;
			
		}
		
		for(int ii =0; ii<N; ii++)
	{
		for(int jj=0; jj<N; jj++)	
			System.out.print(M[ii][jj]+" ");
	 
	System.out.println();
	}
		
		
	}
	
	
	
	
	
	
}

