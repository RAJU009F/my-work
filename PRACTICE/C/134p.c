#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
int arerotations(char *str1,char *str2)
    {
        int s1=strlen(str1);
    
        char temp[s1];
        
        strcat(temp,str1);
        strcat(temp,str1);
        
        if(strstr(temp,str2))
            return 1;
        else
            return 0;    
    
    
    
    }


main()
    {
        char str1[]="ABACD";
        char str2[]="ACDABAC";
        if(arerotations(str1,str2))
            printf("yes\n");
        else
            printf("No\n");    
        
        
    
    
    }

