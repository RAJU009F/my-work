#include<stdio.h>
#include<string.h>

struct A
    {
        char a;
       int i;
    
    }a;
    
struct B
    {
        short s;
        char c;
        int j;
    
    
    }b;
struct C
    {
           double d;
            short a;
            char cq;
    
    }c1;
struct D
    {
        char g6;
        double d1;
        int i1;
        
    
    
    }d;    
        




main()
    {
        char c[200]="naxlite";
        
        printf("%c\n\n",c[5]);
    printf("sizeof(a)::\t%d\n",sizeof(a));
     printf("sizeof(b)::\t%d\n",sizeof(b));
      printf("sizeof(c)::\t%d\n",sizeof(c1));
       printf("sizeof(d)::\t%d\n",sizeof(d));
    }
