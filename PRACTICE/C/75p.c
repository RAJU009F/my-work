#include<stdio.h>


main()
    {
    int a=10;
    
    int *p=&a;
    *p=(int *)20;
    printf("\n%d\n",a);
    int far *q;
    printf("\n%d\n",sizeof(q));
    
    
    }
