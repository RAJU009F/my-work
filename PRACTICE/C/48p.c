#include<stdio.h>

main()
    {
        int n,i,j;
        printf("\nEnter n Value:");
        scanf("%d",&n);
        int A[n];
        for(i=0;i<n;i++)
            {
                scanf("%d",&A[i]);
            
            }
         n=sizeof(A)/sizeof(A[0]);
         for(i=0,j=n-1;i<j;)
            {
                if(A[i]>A[j])
                    {
                        int t=A[i];
                        A[i]=A[j];
                        A[j]=t;
                        j--;
                     
                    }
                 else
                    {
                        i++;
                        
                    }   
            
            
            }   
        
        for(i=0;i<n;i++)
            printf("[%d]\t",A[i]);
    
    
    
    
    }
