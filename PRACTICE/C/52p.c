#include<stdio.h>

int main()
    {
        FILE *p;
        char c;
        p=fopen("52p.c","r");
        while((c=getc(p))!=-1)
            putchar(c);
       fclose(p);
       return 0;
        
    }   

