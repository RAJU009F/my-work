#include<stdio.h>
#include<stdlib.h>

main()
    {
    int a[]={91,32,63,24,75,3,68,23};
    
    quicksort(a,0,7);
    int i;
    printf("after sorting:");
    for(i=0;i<8;i++)
        printf("[%d]\t",a[i]);
    
    
    }
void quicksort(int s[],int first,int last)
    {
        if(first<last)
            {
                int i=first;
                int j=last;
                int p=first;
            while(i<j)
                {
                    if(s[i]<s[p] && i<last)
                        i++;
                    if(s[j]>s[p])
                        j--;
                    if(i<j)
                       { 
                       int t=s[i];
                         s[i]=s[j];
                         s[j]=t;
                        }        
                }   
                
                 int t=s[i];
                 s[i]=s[p];
                 s[p]=t; 
                 
                 
                   quicksort(s,first,j-1);
                   quicksort(s,j+1,last);     
            
            
            }
    
    
    }    
