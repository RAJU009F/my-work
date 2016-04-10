/*   BAYER MOORE BAD CHARACTER HUERISTIC  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CHAR 256
void badchar(char *p,int *bad,int m)
    {
        int i=0;
        for(i=0;i<CHAR;i++)
            {
                bad[i]=-1;
            
            }
            
        for(i=0;i<m;i++)
            {
            
                bad[p[i]]=i;
            }    
    
    
    }
int max(int a,int b)
    {
        return a>b?a:b;
    
    }

void search(char *t,char *p)
    {
        int bad[CHAR];
        int m=strlen(p);
        int n=strlen(t);
        badchar(p,bad,m);    
        int s=0;
        while(s<=n-m)
            {
                int j=m-1; 
               while(j>=0 && p[j]==t[s+j])
                    j--;
              if(j<0)
                {
                    printf("\npattern occured at shift=%d\n",s);
                    s+=(s+m<n)?m-bad[t[s+m]]:1;
                }          
                
              else
                s+=max(1,j-bad[t[s+j]]);  
            
            
            
            
            
            }
    
    
    
    }

main()
    {
        char p[]="AAAC";
        char t[]="AAACAAAAAC";
        search(t,p);
    
    
    
    }

    
