#include<stdio.h>
    
    
main()
    {
   
        int v=100;
        char c='N';
        
        char *q=&c;
          int *ptr=&v;
        void *p;
        
        p=ptr;
        
        printf("\n%d\n",*(int *)p);
        p=q;
        printf("\n%c\n",*(char *)p);   
        printf( " %d \n\n",sizeof(c));
        
        char *str=NULL;
        
        strcpy(str,"naxalite");
        printf("%s",str);
        
        
    
    
    }    
