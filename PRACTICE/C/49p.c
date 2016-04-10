#include<stdio.h>

#include<stdlib.h>

struct ST
    {
        int sid;
        char* name;
        struct 
            {
                int rank;
                float g;
            
            }p;
    
    
    
    };

main()
    {
        
        struct ST *s;
        s=malloc(sizeof(struct ST));
        s->sid=9;
        s->name="nax";
        s->p.rank=1;
        
        printf("[%d]\t[%s]\t[%d]\t[%f]",s->sid,s->name,s->p.rank,s->p.g);
        
    
    
    }
