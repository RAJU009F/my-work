#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printIR(char *str1,char *str2,char *str,int m,int n,int i);
void printI(char *str1,char *str2) ;
main()
    {
        char str1[]="ABC";
        char str2[]="DE";
        printI(str1,str2);
    
    
    }
    
void printI(char *str1,char *str2)  
    {
        int m=strlen(str1);
        int n=strlen(str2);
        
        char *str=(char *)malloc(sizeof(char)*(m+n+1));
        
        str[m+n+1]='\0';
        printIR(str1,str2,str,m,n,0);
        
        free(str);
    
    
    
    }    
void printIR(char *str1,char *str2,char *str,int m,int n,int i)
    {
        if(!m && !n)
            printf("%s\n",str);
        if(m)
            {
                str[i]=str1[0];
                printIR(str1+1,str2,str,m-1,n,i+1);
            
            }    
        if(n)
            {
                str[i]=str2[0];
                printIR(str1,str2+1,str,m,n-1,i+1);
            
            }
    
    
    
    }
