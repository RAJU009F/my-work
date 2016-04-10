#include<stdio.h>
#include<stdlib.h>
#define MAX 256
void quicksort(char str[],int first,int last)
    {
        if(first<last)
            {
                int i,j,p;
                i=first;
                j=last;
                p=first;
                
                while(i<j)
                    {
                        while(i<last && str[i]<str[p])
                            i++;
                        while(str[j]>str[p])
                            j--;
                        if(i<j)
                            {
                                char c=str[i];
                                str[i]=str[j];
                                str[j]=c;
                            
                            }        
                    
                    
                    }
                   char t=str[p];
                   str[p]=str[j];
                   str[j]=t;
                   
                   quicksort(str,first,j-1);
                   quicksort(str,j+1,last); 
            
            
            }
    
    }


char *removeD(char *str)
    {
        int len=strlen(str);
        quicksort(str,0,len-1);
        int in=1,rin=1;
        while(*(str+in))
            {
                if(*(str+in)!=*(str+in-1))
                    {
                        *(str+rin)=*(str+in);
                        rin++;
                    }
                    in++;
            }
            
         *(str+rin)='\0';
         return str;   
        
    
    
    }


main()
    {
        char str[]="indiaan Hitler";
        
        printf("%s\n\n",removeD(str));
    
    
    
    }


