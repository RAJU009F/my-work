#include<stdio.h>


main()
    {
    
    const  int j=2;
    
    printf("\n%d\n",j);
    int *ptr=&j;
    *ptr=(int *)30;
    
     printf("\n%d\n",j);
    
  *ptr=(int *)305;

    
     printf("\n%d\n",j);
    
    
    
    }
