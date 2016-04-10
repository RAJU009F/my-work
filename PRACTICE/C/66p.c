#include<stdio.h>

#include<stdlib.h>

void merge(int *,int *,int,int);
void print(int *,int);

main()
    {
        int m,n,i,j;
        
        printf("\nEnter size of A and B:");
        scanf("%d %d",&m,&n);
        
        int a[m+n],b[n];
        printf("\nenter the elements for A:\n");
        
        for(i=0;i<m;i++)
            scanf("%d:",&a[i]);
            
        printf("\nEnter the elemnts for B:\n");
        for(i=0;i<n;i++)
            scanf("%d:",&b[i]);
            
            
         print(a,m);
         print(b,n);
         merge(a,b,m,n);
         print(a,m+n);       
        
        
        
    
    
    
    }
void merge(int x[],int y[],int m,int n)
    {
    
       //int m=sizeof(x)/sizeof(x[0]);
      // int n=sizeof(y)/sizeof(y[0]);
        
        int i=m+n-1;
        int j=m-1;
        int k=n-1;
        
        while(j>=0 && k>=0)
            {
            
                if(x[j]>y[k])
                    {
                        x[i]=x[j];
                        j--;
                    
                    }
                 else
                    {
                        x[i]=x[k];
                        k--;
                    
                    
                    }
                    
                   i--; 
                     
            
            
            } 
            
            while(k>=0)
                {
                    x[i]=y[k];
                    k--;
                    i--;
                
                }
    
    
    
    }    
    
 void print(int x[],int m)
    {
        //int m=sizeof(x)/sizeof(x[0]);
        printf("size:%d",m);
        int i=0;
        printf("\n\n\n");
        while(i<m)
            {
                printf("[%d]\t",x[i]);
                i++;
            
            }
        printf("\n\n\n");
    
    
    }   
    
    
