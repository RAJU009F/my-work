#include<stdio.h>
#include<stdlib.h>

int mul(int ,int);
main()
    {
        int a,b,r;
        printf("\nenter a:");
        scanf("%d",&a);
        printf("\nenter b:");
        scanf("%d",&b);
        
       r=mul(a,b);
       printf("fsdfsf");
        printf("\n%d * %d::%d",a,b,r);
                    
    
    
    }
    
  int mul(int c,int d)
    {
        if(c==0||d==0)
            return c*d;
        
            return (mul(c,--d)+c);  
    
    
    
    }  
