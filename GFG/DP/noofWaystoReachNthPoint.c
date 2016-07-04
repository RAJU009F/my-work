#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: DP
# Problem Statement	: There are N points on the road ,you can step ahead by 1 or 2 . Find the number of ways you can reach at point N. For example: 
						for n=4 we have 5 possible ways [1,1,1,1]  [1,1,2]  [1,2,1]  [2,1,1]  [2 2].
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/


long noofWays(int N)
    {
        long a=1, b=2;
        if(N<=1)
            return 1;
        int i;
        
        for(i=0; i<N-2; i++)
            {
                long temp = a+b;
                a = b;
                b =temp;
                
            }
        
        return b;
        
    }
int main() {

    int T;
    int N;
    scanf("%d",&T);
    if(T<0 || T>100)
        return;
    while(T>0)
    {
        scanf("%d",&N);
        if(N<0 || N>100)
            return;
        printf("%ld \n",noofWays(N));    
        
        T--;
    }
    
	return 0;
}