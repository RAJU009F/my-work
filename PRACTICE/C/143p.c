#include<stdio.h>
#include<stdlib.h>
void search(char *t,char *p)
    {
        int n=strlen(t);
        int m=strlen(p);
        
        int i,j;
        for(i=0;i<=n-m;)
            {
            
                for(j=0;j<m;j++)
            
                {
                    if(p[j]!=t[i+j])
                        break;
                
                } 
               if(j==m)
                {
                    printf("pattern occured at %d\n\n",i);
                    i=i+m;
                
                } 
                
             else if(j==0)
                {
                    i=i+1;
                
                }  
               else
                i=i+j; 
                
                           
            }
    
    
    }

main()
    {
        char p[]="ABCD";
        char t[]="ABCEABCDABCEABCD";
        search(t,p);
        
    }
