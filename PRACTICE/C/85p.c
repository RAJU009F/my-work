#include<stdio.h>

void fun();


main()
    {
   
    
    printf("main\n");
     atexit(fun);
    
    }
    
  void fun()
    {
        printf("\nfunction\n");
    
    }  
