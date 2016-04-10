#include<stdio.h>

int f(int ,int);
float f(float,float);

main()
    {
    
        int a,b;
        float c,d;
        int r1,r2;
        printf("Enter int s :");
        scanf("%d%d",&a,&b);
        
        printf("Enter float s:");
        scanf("%f %f"&c,&d);
        
        r1=f(a,b);
        r2=f(c,d);        
    
    printf("int result: %d  and float result: %d ",r1,r2);
    
    }    
    
 int f(int x,int y)
    {
        return x*y;
    
    
    
    }   
    
   float f(float x,float y)
        {
            return x*y;
        }
