#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b)
    {
        return a>b?a:b;
        
        
    
    }

int LCSstr(char *x,char *y)
    {
        int m=strlen(x),i;
        int n=strlen(y),j;
        int res=0;
        int L[m+1][n+1];
        
        
        for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                    {
                        if(i==0||j==0)  
                            L[i][j]=0;
                        if(x[i-1]==y[j-1])
                            {
                                L[i][j]=L[i-1][j-1]+1;
                                res=max(res,L[i][j]);
                            
                            }    
                        else
                            L[i][j]=0;    
                    
                    
                    }
            
            
            
            }
    
            return res;
    
    
    }
main()
    {
        char str1[]="newsite:geeksquiz.com";
        char str2[]="oldsite:geeksforgeeks.org";
        
        printf("length of longest sustr:%d\n\n\n\n",LCSstr(str1,str2));
    
    
    }
