#include<stdio.h>
#include<stdlib.h>
void show(char *s,int n)
    {
        int i;
        for(i=0;i<n;i++)
            printf("%.2x",s[i]);
    
    }
main()
    {
        int i=0x01234567;
        
        show((char*)&i,sizeof(i));
        
       unsigned int i1=1;
        char *c=(char *)&i1;
        if(*c)
            printf("little");
         else
            printf("bgg");   
    
    
    }
