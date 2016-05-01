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
// Project Euler #2: Even Fibonacci numbers
public class Solution {

    public static void main(String[] args) {
        
        Scanner  sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while(T>0)
                {
                
            long N = sc.nextLong();
            long a = 1;
            long b =  2;
            long evenSum = 0;
            while(a<=N)
                {
                    if(a%2 == 0)
                        evenSum += a;
                long c = a+b;
                a = b;
                b = c;
             }
            
            System.out.println(evenSum);
            T--;
        }
        
    }
}