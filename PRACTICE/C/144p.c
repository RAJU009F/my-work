/* printitng all permutations with rep*/

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
int  compare(const void *a,const void  *b);


void print(char *str,char *d,int index,int n)
    {
        int i,len=strlen(str);
        
            for(i=0;i<len;i++)
                {
                    d[index]=str[i];
                    if(index==n)
                         printf("%s\n",d);
           
                    else
                        print(str,d,index+1,n);                
                }
    
    
    
    }
void printpermute(char *str)
    {
        char *d=(char *)malloc(sizeof(char)*strlen(str));
        int len=strlen(str);
        d[len]='\0';
        
        qsort(str,len,sizeof(char),compare);
        
        print(str,d,0,len-1);
    
    }
    
  int compare(const void *a,const void *b)
    {
        return *((char *)a)-*((char *)b);
    
    }  


main()
    {
        char str[]="NAX";
        printpermute(str);
        
    
    
    }
