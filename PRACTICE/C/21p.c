#include<stdio.h>
#include<stdlib.h>
int add(int, int );
main()
    {
        int a=4,b=4;
        
        printf("addition of %d and %d is:%d",a,b,add(a,b));
    
    
    
    }
    
    
   int add(int m,int n)
    {
        char *c=(char *)m;
        return &c[n]; 
    
    
    
    } 
