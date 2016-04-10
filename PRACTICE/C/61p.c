#include<stdio.h>
#include<stdlib.h>
void swap(char *,char *);
void permute(char *,int ,int);
main()
    {
        char c[100];
        printf("\nEnter string :");
        scanf("%s",c);
        permute(c,0,strlen(c)-1);
    
    
    
    
    }
    
    void permute(char s[],int m, int n)
        {
            if(m==n)
                printf("%s\n",s);
                
             else
                
                {
                    int i;
                    for(i=m;i<=n;i++)
                        {
                            swap(s+m,s+i);
                            permute(s,m+1,n);
                            swap(s+m,s+i);
                        
                        
                        }
                
                
                
                }
                
                
               }    
        
        
void swap(char *s1,char *s2)
    {
            char t=*s1;
            *s1=*s2;
            *s2=t;
    
    
    }        
        
    
