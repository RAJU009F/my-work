#include<stdio.h>
#include<stdlib.h>

void print(char *str)
    {
        if(*str)
        {    
            print(str+1);
            printf("%c",*str);
        }
    }
    
void printnon(char *str) 
    {
        int i=1;
            while(*(str+strlen(str)-i))
                printf("%c",*(str+strlen(str)-i++));
    
    
    }   

main()
    {
    
        char str[]="i ekil siht margorp yrev hcum";
        print(str);
        printf("\n");
        printnon(str);
         printf("\n");
    }
    
    

