#include<stdio.h>
#include<stdlib.h>

void mycat(char *src,char *dst)
    {
        (*dst)?mycat(src,++dst):(*dst++=*src++)?mycat(src,dst):0;
    
   
    
    
    }
int mycmp(char *src,char *dst)
    {
    
        return (*src!=*dst)?0:(*src==*dst)?mycmp(++src,++dst):1;
    
    }
main()
    {
        char src[100]="geeksfor";
        char dst[100]="geeks";
        
        mycat(src,dst);
        
        printf("%s",dst);
        
        if(mycmp(src,dst))
            printf("Equal\n\n");
        else
            printf("\n\nNot Equal\n\n");            
    
    
    }

