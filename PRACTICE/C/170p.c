#include<stdio.h>
#include<stdlib.h>


main()
    {
    
         int *ptr=(int *)malloc(sizeof(int));
         
         *ptr=10;
         *(ptr+1)=20;
         
         ptr=(int *)realloc(ptr,sizeof(int)*4);
         
         *(ptr+2)=40;
         *(ptr+3)=30;
         *(ptr+4)=45;
         while(*ptr)
            {
                printf("[%d]\t",*ptr);
                
            ptr++;
            }
    
    
    }
