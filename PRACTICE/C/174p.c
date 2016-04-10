#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b)
    {
    
        return *((int *)a)-*((int *)b);
    }
main()
    {
    int a[]={12,67,89,453,3,67,7834,23,6,7};
    
    qsort(a,10,sizeof(a[0]),compare);
    int i;
    for(i=0;i<10;i++)
        {
            printf("[%d]\t",a[i]);
        
        }
    
    
    
    }
