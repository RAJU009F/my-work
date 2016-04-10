#include<stdio.h>


void fun();
main()
    {
    static int i=1000;
       i++;
        printf("%d",i); 
        fun();
          printf("\n%d\n",i);
          
            int a=5,b=9,c=67;
            
            printf("\n\n\n&a-7b=%d\t&b-&a=%d\t&c-&a=%d\n",&a-&b,&b-&a,&c-&a);
    
    }
 
void fun()
    {
    int i=900;
        printf("\n%d\n",i);
        i++;
    
    
    }
