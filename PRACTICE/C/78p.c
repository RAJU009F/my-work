#include<stdio.h>
void fun();
main()
    {
        static int m=1;
        
        if(1==1)
            {
                printf("%d\n",m++);
                
                static int m=10;
                printf("%d\n",++m);
                fun();
                printf("%d\n",m++);
            
            
            }
    
     printf("%d\n",m);
            
    
    }
    
void fun()  
    {
    
    //printf("%d",m);
    
    static int m=4;
     printf("%d\n",m);
             
    
    }  
