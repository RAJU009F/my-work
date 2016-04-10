#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define NIL -1
int lookup[MAX];
void _initialize()
    {
    
        int i=0;
        for(i=0;i<MAX;i++)
            lookup[i]=NIL;
    
    
    }

int fibm(int n)
    {
        if(lookup[n]==NIL)
            {
                if(n<=1)
                    lookup[n]=n;
                 else
                    lookup[n]=fibm(n-1)+fibm(n-2);   
            
            
            }    
          return lookup[n];  
    
    
    }

int f(int n)
    {
        if(n<=1)
            return n;
         else
            return f(n-1)+f(n-2);   
    
    }
int fibt(int n)
    {
        int f[n+1];
        f[0]=0; f[1]=1;
        int i;
        for(i=2;i<=n;i++)
            f[i]=f[i-1]+f[i-2];
        
        return  f[n];    
    
    
    
    }    
    
    
main()
    {
        int n=40;
        _initialize();
        printf("Enter :");
        scanf("%d",&n);
        printf("fibm is:%d\n",fibm(n));
        printf("fibt is:%d\n",fibt(n));    
    }
