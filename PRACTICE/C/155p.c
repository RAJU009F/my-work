#include<stdio.h>
#include<stdlib.h>
#define Y 0
#define N 1
int countwords(char *str)
    {
        int wc=0;
        int state=Y;
        
        while(*str)
            {
            
                if(*str==' '||*str=='\t'||*str=='\n')
                    {
                        state=Y;
                    
                    
                    }
                else if(state==Y)
                    {
                        state=N;
                        ++wc;
                    
                    }
            
                str++;
            } 
        return wc;
    
    
    
    }


main()
    {
        char str[]="NAX is NAX indian hitler alegxander vivekananad ramanujan";
        printf("No of words : %d \n\n",countwords(str));
    
    
    
    
    
    
    }
