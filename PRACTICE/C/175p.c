#include<stdio.h>
#include<signal.h>

void signalh(int sig_num )
    
    {
        //signal(SIGINT,signalh);
        printf("\nCannot be terminated using ctrl+c\n");    
    
        fflush(stdout);
    }
    
main()
    {
    
        signal(SIGINT,signalh);
        printf("\n");
        while(1)
            {}
    
    
    }    
