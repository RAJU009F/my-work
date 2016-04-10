#include<stdio.h>
#include<stdlib.h>
#define MAX 256
void printnonrepeat(char *s)
    {
        int count[MAX]={0};
        int i=0;
        while(*(s+i))
           { count[*(s+i++)]++;
               // i++;
           }
           i=0; 
        while(1)
            {
                if(count[*(s+i)]==1)
                   { printf("%c\n\n",*(s+i));
                        return;
                    }
                    
                i++;
            }    
        
    
    
    }


main()
    {
        char s[]="geeksforgeeks";
        
        printnonrepeat(s);
    
    }
