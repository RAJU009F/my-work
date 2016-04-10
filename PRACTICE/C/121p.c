#include<stdio.h>
#define square(x) (x*x) 
main()
    {
        char *ptr="geeksforgeeks";
        printf("%c\n",**&*&ptr);
        
        printf("%s\n\n",*&*&ptr);
     
     
     /*     ACCESSING MACRO    */   
        int x;
        x=36/square(6);
        
        printf("%d\n\n",x);
        
     /*     DIFF BW THE CONSTATN POINTER AND POINTER TO A CONSTANT      */
        int a=10;
        
        int * const ptr=&a;
        
        ++*ptr;
        printf("%d\n\n",*ptr);
           
        
    
    }
