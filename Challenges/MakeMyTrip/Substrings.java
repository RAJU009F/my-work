
import java.util.*;
import java.io.*;


/*

# Author			: @RAJ009F
# Topic or Type 	: Make My trip challenge
# Problem Statement	: total noof strings having ends with X annd Y both sides
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
        
        int N =  sc.nextInt();
        String S = sc.next();
        
        int Q =  sc.nextInt();
        
        while(Q>0)
        	{
        		char X =  sc.next().charAt(0);
        		char Y =  sc.next().charAt(0);
        		int total = 0;
        		for(int i=0; i<N-1; i++)
        			{
        				if(S.charAt(i) == X || S.charAt == Y)
        					{
        						char s =  X;
        						char d = Y;
        						if(S.charAt(i) == Y)
        							{
        								s = Y;
        								d = X;
        							}
        						for(int j= i+1; j<N; j++)
        							{
        								if(S.charAt(j) == d)
        									total +=1;
        								
        							}
        						
        					}
        			}
        		System.out.println(total);
        		Q--;
        	}
        
        
    }
}
