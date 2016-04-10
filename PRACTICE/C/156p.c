#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool match(char *f,char *s)
    {
        if(*f=='\0'&&*s=='\0')
            return true;
         if(*f=='*'&&*(f+1)!='\0'&&*s=='\0')
                return false;
         if(*f=='?'||*f==*s)
            return match(f+1,s+1);
         if(*f=='*')
            return match(f+1,s)||match(f,s+1);             
    
    
        return false;
    
    
    }
void test(char *f,char *s)
    {
        match(f,s)?puts("Y"):puts("N");
    
    
    }

main()
    {
        test("g*k","geeksforgeek");
        printf("\n\n");
        test("ge?k","geek");
        printf("\n\n");
       test("geek*ks","geeksforgeeks");
        printf("\n\n");
        test("NA*E","NAXALITE");
        printf("\n\n");
               test("N8888*i","N888888K");
        printf("\n\n");
    
    
    }
