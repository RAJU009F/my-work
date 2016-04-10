#include<stdio.h>
#include<stdlib.h>
void swap(char *x,char *y)
    {
        char t=*x;
        *x=*y;
        *y=t;
    
    }

void permute(char *s,int i,int n)
    {
        if(i==n)
            printf("%s\n",s);
            
          else
          {  
            int k=i;
            for(k;k<=n;k++)
                {
                    swap(s+i,s+k);
                    permute(s,i+1,n);
                    swap(s+i,s+k);
                
                }
        }
    
    }




main()
    {
       
        char s[]="NAX";
        permute(s,0,strlen(s)-1);
    
    
    }
