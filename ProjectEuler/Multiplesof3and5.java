import java.util.*;
import java.io.*;


/*

# Author			: @RAJ009F
# Topic or Type 	: Java Collection :  group of objects as a single unit
# Problem Statement	: 
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/
public class Solution {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int T = sc. nextInt();
        
        while(T>0)
            {
                
            long N =  sc.nextInt();
            
            long tsum  =  (((N-1)/3)*(2*3+ ((N-1)/3-1)*3))/2;
            long fsum =  (((N-1)/5)*(2*5+ ((N-1)/5-1)*5))/2;
            long ffsum = (((N-1)/15)*(2*15+ ((N-1)/15-1)*15))/2;
            System.out.println(tsum+fsum-ffsum);
            
            
            T--;
        }
        
    }
}