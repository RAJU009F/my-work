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
void quicksort(int a[],int first,int last)
    {
        if(first<last)
            {
                int i,j,p;
                i=first;
                j=last;
                p=first;
                
                while(i<j)
                    {
                       while(a[p]>a[i]&&i<last)
                            i++;
                        while(a[p]<a[j])
                            j--;
                            
                         if(i<j)
                            {
                                int t=a[i];
                                a[i]=a[j];
                                a[j]=t;
                            }                   
                    }
                 int t=a[p];
                 a[p]=a[j];
                 a[j]=t;   
                    
                    
                    
            
            
            quicksort(a,first,j-1);
            quicksort(a,j+1,last);
            
            }
            
    
    
    
    }    
    
