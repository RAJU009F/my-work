#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int myatoi(char *str)
    {
            int res=0;
            int i=0;
            int sign=1;
            
            if(str[i]=='-')
                {
                
                    sign=-1;
                    i++;
                
                }
            for(;str[i];i++) 
                {
               //     if(isNumericChar(str[i]==false))
                 //       return 0;
                        
                    res=res*10+str[i]-'0';    
                
                }    
            return sign*res;
    
    
    }

main()
    {
        char str[]="-454676";
        
        printf("Result: %d \n\n",myatoi(str));
    
    
    }
