#include<stdio.h>

int sum(int ,int ,int);

main()
    {
    
        int x=10,y=300,z=20;
        int v=sum(x,(x,y,z,x),z);
        printf("%d\n",v);
    
    
    
    }
    
int sum(int a,int b,int c)
    {
    
        return a+b+c;
    
    }    
