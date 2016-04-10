#include<stdio.h>
#include<stdlib.h>


#include<string.h>
#include<stdbool.h>
int isInter(char *str1,char *str2,char *str);

main()
    {
        char str1[]="ABC";
        char str2[]="DE";
        char str[34];
        scanf("%s",str);
        
        if(isInter(str1,str2,str))
            printf(" yes\n");
        else
            printf("no\n");        
    
    
    
    
    }
    
int isInter(char *str1,char *str2,char *str)
    {
        int m=strlen(str1);
        int n=strlen(str2);
        if(m+n!=strlen(str))
            return false;
        while(*str)
            {
                if(*str==*str1)
                    str1++;
                    
                  else if(*str==*str2)
                    str2++;  
            
                    else
                        return false;
                    str++;    
            
            
            
            }
          if(*str1||*str2)
                return false;
          
          return true;        
    
    
    }    
