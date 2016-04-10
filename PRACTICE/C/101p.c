#include<stdio.h>
#include<stdbool.h>
int ismatch(int *,int ,int);



main()
    {
        int a[]={2,5,78,33,988,22,4};
        int n;
        printf("\nEnter a Num:");
        scanf("%d",&n);
        if(ismatch(a,7,n))
            printf(" pair is there\n");
        else
            printf("doesn't exist\n");
    
    }

int ismatch(int a[],int s,int n)
    {
        bool b[1000]={0};
        int i=0;
       for(i;i<s;i++)
            {
                if((n-a[i])>=0 && b[n-a[i]]==1)
                    {
                       return 1; 
                    
                    }
                  b[a[i]]=1;  
            
            
            }
        
    
        return 0;
    
    }


