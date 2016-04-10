#include<stdio.h>
int main(){
        
    FILE *p;
    p=fopen("50p.c","r");
    char c;
    while((c=getc(p))!=-1)
      {  putchar(c); }
        
    fclose(p);
    return 0;
    
    }
