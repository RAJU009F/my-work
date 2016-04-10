#include<stdio.h>

#include<stdlib.h>

int lcm(int,int);

int lcm1(int,int);
main()
    {
        int a,b,l;
        printf("\n Enter a : ");
        scanf("%d",&a);
    
        printf("\n Enter a : ");
        scanf("%d",&b);
        
       l=lcm1(a,b);
       printf("\n%d\n",l);
    
    
    }
    
 int lcm(int a, int b)
    {
    
        static int t=1;
        
        if(t%a==0 && t%b==0)
           return t;
            
            
            t++;
            lcm(a,b);
    
    
    
    
    }   
    
 int lcm1(int a,int b)
    {
        static int t=1;
        
        while(t%a!=0 || t%b!=0)
            {
                t++;
            
            }
        return t;
    
    
    
    
    
    }   
