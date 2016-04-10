#include<stdio.h>
#include<stdlib.h>
int add(int m,int n)
    {
        char *c=(char *)m;
        return &c[n];
    
    }

main()

    {
    
    printf("%d\n",add(2,7));
    
    
    }
