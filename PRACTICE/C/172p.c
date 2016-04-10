#include<stdio.h>
int x=10;
int f()
    {
        x=x+10;
    
        return x;
    }
int f1()
    {
        x=x-5;
        return x;
    
    
    }
main()
    {
    int p=f()+f1();
    
    printf("%d\n",p);
    
    }
