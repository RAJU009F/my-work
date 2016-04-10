#include<stdio.h>
#include<stdlib.h>
#define MAX 256


char getmaxchar(char *);


main()
    {
        char *str="geeksforgeeks";
        printf("MAX CHAR :%c \n\n\n",getmaxchar(str));
    
    
    
    }
    
char getmaxchar(char *s)
    {
        int count[MAX]={0};
        int i;
        for(i=0;*(s+i);i++)
            count[s[i]]++;
          int max=0;
         for(i=0;i<MAX;i++)
            {
                if(count[i]>count[max])
                    max=i;    
            }   
    
        return max;
    
    }    

