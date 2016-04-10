#include<stdio.h>
#include<stdlib.h>


void permute(char *,int i,int j);
void swap(char *,char *);


main()
    {
    
    char s[20];
    printf("\n Enter str:");
    scanf("%s",s);
    
    permute(s,0,strlen(s)-1);
    
    
    
    }
    
 void permute(char str[],int i,int j) 
    {
        if(i==j)
            {
                printf("%s\n",str);
            
            }
            
            int k=i;
          for(k=i;k<=j;k++)
            {
                swap(str+i,str+k);
                permute(str,i+1,j);
                swap(str+i,str+k);
            
            
            }  
            
    
    
   
    }   
    
 void swap(char *x,char *y)
    {
        char t=*x;
        *x=*y;
        *y=t;
    
    
    }   
    
