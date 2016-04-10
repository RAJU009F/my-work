#include<stdio.h>
#include<stdlib.h>

main()
    {
    const int i=100;

    printf("first:%d\n",i);
   int  *ptr=&i;
   *ptr=200;
    printf("second:%d\n",i);
    
  register int a=100;
  int *p=&a;
  printf("%d",*p);  
    
    }
