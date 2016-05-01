


import java.util.*;
import java.io.*;


/*

# Author			: @RAJ009F
# Topic or Type 	: MAke My trip challenge
# Problem Statement	: print the postion of the next greater element
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/
class TestClass {
    public static void main(String args[] ) throws Exception {
      
      Scanner sc = new Scanner(System.in);
      
      int N = sc.nextInt();
      int Q = sc.nextInt();
      int[] arr =  new int[N];
      for(int i=0; i<N; i++)
			arr[i] = sc.nextInt();
	while(Q>0)
		{
			int f = sc.nextInt();
			if(f == 1)
				{
					int v = sc.nextInt();
					int pos = -1;
					for(int i=0; i<N; i++)
						{
							if(arr[i]>=v)
								{
									pos = i+1;
									break;
								}
						}
					System.out.println(pos);	
				}else
				{
					int x =  sc.nextInt();
					int y =  sc.nextInt();
					arr[x-1] = y;
					
					
				}
			
			Q--;
			
		}
			
    }
}