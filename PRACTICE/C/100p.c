#include<stdio.h>
#include<stdlib.h>

void quicksort(int *,int ,int);
int partition(int *,int ,int);
void exchange(int *,int *);


main()
    {
        int a[]={23,5,6,21,667,88,11,3,5,1};
        quicksort(a,0,(sizeof(a)/sizeof(a[1])-1));
        int i;       
        for(i=0;i<10;i++)
            printf("[%d]\t",a[i]);
    
    }

void quicksort(int t[],int si,int ei)
    {
    
        if(si<ei)
            {
               int pi=partition(t,si,ei);
                quicksort(t,si,pi-1);
                quicksort(t,pi+1,ei);
            }
    
    
    }
int partition(int t[],int si,int ei)
    {
        int i=si+1,j=ei,k;
        int x=t[si];
       for(i;i<j;i++)
        {
            if(t[i]>x&&t[j]<x)
                {
                    exchange(&t[i],&t[j]);
                
                }
                j--;
        
        
        }
        exchange(&t[i],&x);
            
        return i;    
        
    
    
    }
void exchange(int *m,int *n)
    {
        int t=*n;
        *n=*m;
        *m=t;
        
    }    
    

