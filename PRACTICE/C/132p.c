#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 256
void printdupchar(char *str)
    {
        bool B[MAX]={0};
        int i=0;
        while(*(str+i))
            {
                if(B[*(str+i)]==1)
                    {
                        printf("%c\t",*(str+i));
                                                              
                    }
                  else 
                    {
                        B[*(str+i)]=1;
                    
                    } 
                     i++;
            
            }
    
    
    
    }

main()
    {
        char str[]="indian hitler to the world";
        
       printdupchar(str);
       
    
    
    
    }
