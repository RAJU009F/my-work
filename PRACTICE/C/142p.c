#include<stdio.h>
#include<stdlib.h>

void compute(char *p,int *lps,int m)
    {
        int len=0;
        lps[0]=0;
       int i=1;
        while(i<m)
            {
                if(p[i]==p[len])
                    {
                        len++;
                        lps[i]=len;
                        i++;
                    }
                 else
                    {
                        if(len)
                            len=lps[len-1];
                         else
                            {
                                lps[i]=0;
                                i++;
                            }   
                    
                    
                    }   
            
            }
    
    }

void KMPsearch(char *t,char *p)
    {
        int n=strlen(t);
        int m=strlen(p);
        
       int *lps=(int *)malloc(sizeof(int)*(m));
        
            compute(p,lps,m); 
            
        int i=0,j=0;
            while(i<n)
                {
                    if(p[j]==t[i])
                        {
                            j++;
                            i++;
                        }
                     if(j==m)   
                        {
                            printf("pattern occured at %d\n",i-j);
                            j=lps[j-1];
                        
                        }   
                      else if(p[j]!=t[i])
                            {
                                if(j)
                                    j=lps[j-1];
                                else
                                    i++;    
                            
                            
                            }
                
                
                }
        
    
    free(lps);
    
    }
main()
    {
        char t[]="AABAACAADAABAAABAA";
        char p[]="AABA";
        KMPsearch(t,p);
    
    
    }    
