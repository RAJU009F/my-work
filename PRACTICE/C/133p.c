#include<stdio.h>
#include<stdlib.h>
#define MAX 256

char *removeC(char *str1,char *str2);
main()
    {
        char str1[]="geeksforgeeksnaxlite";
        char str2[]="masknax";
        
        printf("Resulted str: %s\n\n",removeC(str1,str2));
        
        
    
    
    }

char *removeC(char *str1,char *str2)
    {
        int count[MAX]={0};
        int i=0;
        while(*(str2+i))
            {count[*(str2+i)]++;
              
               i++;
            }
        int i1=0,i2=0;
        while(*(str1+i1))
            {
                if(count[*(str1+i1)]==0)
                    {
                        *(str1+i2)=*(str1+i1);
                        i2++;
                    }
                    i1++;    
                    
            }
        *(str1+i2)='\0';
        return str1;
    }
