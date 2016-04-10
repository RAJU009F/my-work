#include<stdio.h>
#include<stdlib.h>
void start(void )__attribute__((constructor));
void end(void)__attribute__((destructor));
void start(void)
    {
        printf("satrt::\n\n");
    
    }
void end(void)
    {
        printf("end::\n\n");
    
    }    
    

main()
    {
    
        printf("main::\n");
    
    }
