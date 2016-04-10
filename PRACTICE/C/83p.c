#include<stdio.h>

#include<stdlib.h>

void printc(int *,int *,int ,int ,int,int);
void printcomb(int *,int,int );

main()
    {
        int a[]={0,1,2,3,4,5,6,7,8,9};
        
        int n=sizeof(a)/sizeof(a[0]);
        
        int r=3;
        
        printcomb(a,n-1,r);
        
        
    
    
    }

void printcomb(int a[],int n,int r)
    {
        int d[r];
        printc(a,d,0,n,0,r);
    
    }
void printc(int a[],int d[],int start,int end,int index,int r)
    {
          int j;
        if(index==r)
            {
              
                for(j=0;j<r;j++)
                    printf("%d",d[j]);
                printf("\n");
               return;     
            
            
            }
        for(j=start;j<=end && end-j+1>=r-index;j++)
            {
                d[index]=a[j];
                printc(a,d,j+1,end,index+1,r);
            
            }
    
    
    
    
    }    

