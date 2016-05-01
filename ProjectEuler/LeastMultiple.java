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

public class LeastMultiple {

    public static boolean isPrime(int n)
            {
                if(n==2 || n==3)
                       return true; 
                if(n <=1)
                       return false; 
            for(int i=2; i<=n/2; i++)
                        if(n%i==0)
                            return false;
               return true;     
            }
    public static long getNum(int i, long num, int N)
            {
                //long num =  num*i;
                if(i<=1)
                    return num;
                if(num*i>N)
                    return num;
                else
                    return getNum(i,num*i, N);
        
        
             }
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       
        int T = sc.nextInt();
        while(T>0)  
            {
                int N =  sc.nextInt();
                long  lcm = 1;

       
                    for(int i=N; i>=1; i--)
                          {  if(isPrime(i))
                                    {
                                long res =  getNum(i,1, N);
                              //System.out.println(res);
                                lcm *=res;
                                }
                           else
                               {
                               //arr[N-i] = 1;
                               lcm *=1;
                           }
                            
                          }
                  
                
              System.out.println(lcm); 
            
            T--;
         }
        
    }
}