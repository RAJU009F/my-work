#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 256

char *removeD(char *str)
    {
        bool B[MAX]={0};
        int j=0,i=0;
        while(*(str+i))
            {
                if(B[*(str+i)]==0)
                    {
                        B[*(str+i)]=1;
                       *(str+j)=*(str+i);
                       j++;         
                    }
                  i++;  
            
            }
        
    
        *(str+j)='\0';
        return str;
    
    
    }


main()
    {
        char str[]="geeksforgeeks";
        
        printf("%s\n\n",removeD(str));
    
    
    
    
    
    }
