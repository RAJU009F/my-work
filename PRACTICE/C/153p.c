#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
int compare(const void *a,const void *b)
    {
        return *((char *)a)-*((char *)b);
    
    }
    
void swap(char *x,char *y)
    {
        char t=*x;
        *x=*y;
        *y=t;
    
    }    

int findceil(char s[],char first,int l,int h)   
    {
        int index=l;
        
        int i;
        for(i=l+1;i<=h;i++)
            if(s[i]>first&&s[i]<s[index])
                index=i;
         return index;       
    
    
    
    }

void printlex(char *s)
    {
        int m=strlen(s);
        qsort(s,m,sizeof(s[0]),compare);
        
        
        
        bool finish=false;
        
        while(!finish)
            {
                printf("%s\n",s);
                int i;
                for(i=m-2;i>=0;i--)
                    if(s[i]<s[i+1])
                     break;
            
               if(i==-1)
                    finish=true;
                    
               else
                {
                    int ceil=findceil(s,s[i],i+1,m-1);
                    swap(&s[i],&s[ceil]);
                    qsort(s+i+1,m-i-1,sizeof(s[0]),compare);
                
                
                }     
               
            
            
            
            
            
            }
    
    
    
    
    }



main()
    {
        char s[]="RING";
        printlex(s);
    
    
    }
