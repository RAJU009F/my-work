#include<stdio.h>
#include<stdlib.h>

void pattern(char *t,char *p)
    {
      int  n=strlen(t);
       int m=strlen(p);
        int i=0;
        for(i;i<=n-m;i++)
          {  int j=0;
             while(t[i+j]==p[j])
                {
                    j++;
                    
                    if(j==m)
                        printf("pattern occured at %d \n\n",i);
                
                
                }
        }
    
    
    
    
    
    }
main()
    {
        char T[]="india is my country,all indians";
        char P[]="india";
        
        pattern(T,P); 
    
    
    
    
    }
    
    
