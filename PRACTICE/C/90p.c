#include<stdio.h>

main()
    {
    
       int a[]={1,34,565,676,78,2};
       
       int min;
       int max;
       int sum=0;
       int i=0;
       min=a[0];
       max=0;
       for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
        {
            sum+=a[i];
            if(min>a[i])
                min=a[i];
             if(max<a[i])
                max=a[i];   
        
        }
        
        printf("\nmin:%d\tmax:%d\tavg:%d\t\n\n",min,max,sum/i);
        
    
    
    
    
    }
