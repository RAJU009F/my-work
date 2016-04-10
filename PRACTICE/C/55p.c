#include<stdio.h>

main()
    {
        FILE *S,*D;
        S=fopen("fil1","r");
        D=fopen("file2","w");
        char c;
        while((c=getc(S))!=EOF)
           putc(D,c); 
           
        close(S);
        close(D);   
    
    
    }
