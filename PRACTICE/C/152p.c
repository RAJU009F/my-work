#include<stdio.h>
#include<stdlib.h>

int Matrixchain(int a[],int i,int n)
    {
        if(i==n)
            return 0;
        int k;
        int min=10000000;
        int count;
        for(k=i;k<n;k++)
            {
                count=Matrixchain(a,i,k)+Matrixchain(a,k+1,n)+a[i-1]*a[k]*a[n];
                
                if(count<min)
                    min=count;
            
            
            }    
         return min;   
    
    
    
    }

main()
    {
    
    int a[]={10,20,30,40,30};
    int n=sizeof(a)/sizeof(a[0]);
    
    printf("mininmum nof mutilplications:%d\n\n",Matrixchain(a,1,n-1));
    
    
    }
