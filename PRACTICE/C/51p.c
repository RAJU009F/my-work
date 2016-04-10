#include<stdio.h>
int main()

{
    FILE *p;
    char ch;
    p=fopen("51p.c","r");
    while((ch=getc(p))!=-1)
         putchar(ch);
    fclose(p);
    return 0;
}
