#include<stdio.h>
#include<stdlib.h>

main()
    {
        static int i=5;
        if(--i)           
           main();
       printf("%d\t",i);
            
            
            
    
    
    
    
    }


