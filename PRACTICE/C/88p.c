#include<stdio.h>
#include<stdlib.h>



main()
    {
        int N;
        printf("\nEnter N value:");
        scanf("%d",&N);
        int a[N];
        int i;
        
        for(i=1;i<=N;i++)
            {
                if(i==N-1)
                     a[i-1]=N;
                else      
                    a[i-1]=i;
            
            }
        int sum=0;
        for(i=0;i<N;i++)
            sum+=i;
        int sum1=N*(N+1)/2;
        printf(" %d\n",-(sum-sum1));
        
        printf("\n\nDup:\n");
        scanf("%d",&N);
        int s=0;
        for(i=0;i<N;i++)
            {
                if(i==N-1)
                     a[i-2]=N;
               a[i]=i;
            }
            
            for(i=0;i<N;i++)
                {
                    s=s^a[i]^i;    
                
                }
    
        printf("\n\n%d\n",s);
    
    }
